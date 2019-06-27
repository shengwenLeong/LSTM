//
// Created by lswmi on 2019/6/26.
//

#include "lstm.h"


namespace LSTM{

    LSTM::LSTM() : C_last(0) {}
    LSTM::~LSTM(){}

    float LSTM::lstm_(std::vector<float> x_input, std::vector<float> y_input, std::vector<float> Weight_Z,
                      std::vector<float> Weight_I, std::vector<float> Weight_F, std::vector<float> Weight_O,
                      std::vector<float> Recurrent_Z, std::vector<float> Recurrent_I, std::vector<float> Recurrent_F,
                      std::vector<float> Recurrent_O, std::vector<float> Peephole) {
        std::cout <<"======= Content Visual Start ========="<< std::endl;
        for(int i=0; i<4; i++)
        {
            std::cout <<i<<" |";
            std::cout << y_input[i] << " ";
            std::cout << std::endl;
        }
        std::cout <<"======= Content Visual END ========="<< std::endl;

        float Z = 0;

        float Z_xw = 0;
        float Z_yr = 0;

        for(int i=0; i<M_X; i++){
            Z_xw += x_input[i] * Weight_Z[i];
        }

        for(int i=0; i<M_X; i++){
            Z_yr += y_input[i] * Recurrent_Z[i];
        }

        Z = sigmoid(Z_xw + Z_yr);

        std::cout<<"---------------Z_xw--------------"<<Z_xw<<std::endl;
        std::cout<<"---------------Z_yr--------------"<<Z_yr<<std::endl;
        std::cout<<"---------------Z--------------"<<Z<<std::endl;

        //------I---------------
        float I = 0;
        float I_xw = 0;
        float I_yr = 0;

        for(int i=0; i<M_X; i++){
            I_xw += x_input[i] * Weight_I[i];
        }

        for(int i=0; i<M_X; i++){
            I_yr += y_input[i] * Recurrent_I[i];
        }

        I = sigmoid(I_xw + I_yr + C_last*Peephole[0]);

        std::cout<<"---------------I--------------"<<std::endl;

        //------F-------------------

        float F = 0;
        float F_xw = 0;
        float F_yr = 0;

        for(int i=0; i<M_X; i++){
            F_xw += x_input[i] * Weight_F[i];
        }

        for(int i=0; i<M_X; i++){
            F_yr += y_input[i] * Recurrent_F[i];
        }

        F = sigmoid(F_xw + F_yr + C_last*Peephole[1]);

        std::cout<<"---------------F--------------"<<std::endl;
        //--------C-----------------
        float C=0;
        C = Z*I + C_last*F;
        C_last = C;

        //--------O-----------------
        float O = 0;
        float O_xw = 0;
        float O_yr = 0;

        for(int i=0; i<M_X; i++){
            O_xw += x_input[i] * Weight_O[i];
        }

        for(int i=0; i<M_X; i++){
            O_yr += y_input[i] * Recurrent_O[i];
        }

        O = sigmoid(O_xw + O_yr + C*Peephole[2]);

        std::cout<<"---------------O--------------"<<std::endl;

        //--------Y----------------------

        float Y = 0;
        Y = sigmoid(C)*O;

        std::cout<<"---------------Y--------------"<<std::endl;

        return Y;
        }
    }