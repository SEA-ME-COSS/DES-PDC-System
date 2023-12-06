#include "SendSomeipThread.hpp"

using namespace v1_0::commonapi;

void *SendSomeipThread(void *arg)
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<CANSenderStubImpl> CANSenderService;
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy;
    
    runtime = CommonAPI::Runtime::get();
    CANSenderService = std::make_shared<CANSenderStubImpl>();
    runtime->registerService("local", "CANSender", CANSenderService);
    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    // Kalman filter variables and initialization
    double speed_sensor_estimation[SIZE] = {0, 0};
    double speed_sensor_letterP[SIZE][SIZE] = {{100, 0}, {0, 100}};
    double speed_sensor_dt = 1;
    double speed_sensor_renewed_e[SIZE], speed_sensor_renewed_P[SIZE][SIZE];
    double speed_sensor_measuredstate;
    
    int currentIndex;
    
    while (1)
    {
        // Read speed data from speed buffer
        pthread_mutex_lock(&SpeedBufferMutex);
        currentIndex = SpeedBufferIndex - 1;
        if (currentIndex < 0)
        {
            currentIndex = SpeedBuffer_SIZE - 1;
        }
        uint16_t speed_sensor_rpm = SpeedBuffer[currentIndex];
        pthread_mutex_unlock(&SpeedBufferMutex);
        
        speed_sensor_measuredstate = (double)speed_sensor_rpm;
        
        // Apply Kalman filter
        kalmanFilter_(speed_sensor_measuredstate, speed_sensor_estimation, speed_sensor_letterP, speed_sensor_dt, speed_sensor_renewed_e, speed_sensor_renewed_P);
        
        // Update the estimation and covariance for the next iteration
        for (int i = 0; i < SIZE; i++)
        {
            speed_sensor_estimation[i] = speed_sensor_renewed_e[i];
            for (int j = 0; j < SIZE; j++)
            {
                speed_sensor_letterP[i][j] = speed_sensor_renewed_P[i][j];
            }
        }

        // Round the filtered speed value and send it to IPCManager
        uint16_t kf_speed_sensor_rpm = (uint16_t)round(speed_sensor_renewed_e[0]);
        IPCManagerTargetProxy->setSensorRpm(kf_speed_sensor_rpm, callStatus, returnMessage);
        
        // (UP) Sending speed data
        // ==================================================
        // (DOWN) Sending distance data
        
        // Read distance data from distance buffer
        pthread_mutex_lock(&DistanceBufferMutex);
        currentIndex = DistanceBufferIndex - 1;
        if (currentIndex < 0)
        {
            currentIndex = DistanceBuffer_SIZE - 1;
        }
        uint16_t distance = DistanceBuffer[currentIndex];
        pthread_mutex_unlock(&DistanceBufferMutex);

        IPCManagerTargetProxy->setDistance(distance, callStatus, returnMessage);
        
        usleep(300000);  // Sleep for 300 ms
    }
    
    return NULL;
}

// Kalman filter implementation
void kalmanFilter_(double measuredstate, double estimation[SIZE], double letterP[SIZE][SIZE], double dt, double renewed_e[SIZE], double renewed_P[SIZE][SIZE]) 
{
    // Kalman filter constants and parameters
    double letterA[SIZE][SIZE] = {{1, dt}, {0, 1}};
    double letterQ[SIZE][SIZE] = {{100, 0}, {0, 100}};
    double letterH[MEASURE_SIZE][SIZE] = {{1, 0}};
    double letterR[MEASURE_SIZE] = {25};

    // 1. Predict the state and error covariance
    double predicted_e[SIZE];
    double temp_result[SIZE][SIZE];
    matrix_multiply(letterA, (double (*)[SIZE])estimation, temp_result);
    for (int i = 0; i < SIZE; i++)
    {
        predicted_e[i] = temp_result[i][0];
    }
    double predicted_P[SIZE][SIZE];
    matrix_multiply(letterA, letterP, predicted_P);
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            predicted_P[i][j] += letterQ[i][j];
        }
    }

    // 2. Calculate Kalman Gain
    double K[SIZE];
    double denominator = (letterH[0][0] * predicted_P[0][0] + letterH[0][1] * predicted_P[1][0]) * letterH[0][0] 
                         + (letterH[0][0] * predicted_P[0][1] + letterH[0][1] * predicted_P[1][1]) * letterH[0][1] + letterR[0];
    for (int i = 0; i < SIZE; i++) 
    {
        K[i] = (predicted_P[i][0] * letterH[0][0] + predicted_P[i][1] * letterH[0][1]) / denominator;
    }

    // 3. Update the estimation
    double y = measuredstate - (letterH[0][0] * predicted_e[0] + letterH[0][1] * predicted_e[1]);
    for (int i = 0; i < SIZE; i++) 
    {
        renewed_e[i] = predicted_e[i] + K[i] * y;
    }

    // 4. Update the error covariance
    double I[SIZE][SIZE] = {{1, 0}, {0, 1}};
    double KH[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            KH[i][j] = K[i] * letterH[0][j];
        }
    }
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            renewed_P[i][j] = (I[i][j] - KH[i][j]) * predicted_P[i][j];
        }
    }
}

// Matrix multiplication function
void matrix_multiply(double A[SIZE][SIZE], double B[SIZE][SIZE], double result[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) 
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
