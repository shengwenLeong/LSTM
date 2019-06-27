//
// Created by lswmi on 2019/6/27.
//

#include "Fixed_Lstm.h"
#include "Fixed_Sigmoid.h"

namespace Fixed_LSTM{

    Fixed_LSTM::Fixed_LSTM() : C_last((FixedPoint<2,14>)0) {}
    Fixed_LSTM::~Fixed_LSTM() {}

    FixedPoint<2,14> Fixed_LSTM::Fixed_lstm_(std::vector<FixedPoint<1,7>> x_input, std::vector<FixedPoint<2,14>> y_input,
                      std::vector<FixedPoint<1,7>> Weight_Z,std::vector<FixedPoint<1,7>> Weight_I,
                      std::vector<FixedPoint<1,7>> Weight_F,std::vector<FixedPoint<1,7>> Weight_O,
                      std::vector<FixedPoint<1,7>> Recurrent_Z,std::vector<FixedPoint<1,7>> Recurrent_I,
                      std::vector<FixedPoint<1,7>> Recurrent_F,std::vector<FixedPoint<1,7>> Recurrent_O,
                      std::vector<FixedPoint<1,7>> Peephole) {
        std::cout <<"======= Content Visual Start ========="<< std::endl;
        for(int i=0; i<4; i++)
        {
            std::cout <<i<<" |";
            std::cout << y_input[i] << " ";
            std::cout << std::endl;
        }
        std::cout <<"======= Content Visual END ========="<< std::endl;

        FixedPoint<2,14> Z = 0;

        FixedPoint<2,14> Z_xw = 0;
        FixedPoint<2,14> Z_yr = 0;

        for(int i=0; i<M_X; i++){
            Z_xw += x_input[i] * Weight_Z[i];
        }

        for(int i=0; i<M_X; i++){
            Z_yr += y_input[i] * Recurrent_Z[i];
        }

        Z = Fixed_sigmoid(Z_xw + Z_yr);

        std::cout<<"---------------Z_xw--------------"<<Z_xw<<std::endl;
        std::cout<<"---------------Z_yr--------------"<<Z_yr<<std::endl;
        std::cout<<"---------------Z--------------"<<Z<<std::endl;

        //------I---------------
        FixedPoint<2,14> I = 0;
        FixedPoint<2,14> I_xw = 0;
        FixedPoint<2,14> I_yr = 0;

        for(int i=0; i<M_X; i++){
            I_xw += x_input[i] * Weight_I[i];
        }

        for(int i=0; i<M_X; i++){
            I_yr += y_input[i] * Recurrent_I[i];
        }

        I = Fixed_sigmoid(I_xw + I_yr + (C_last*Peephole[0]).convert<2,14>());

        std::cout<<"---------------I--------------"<<std::endl;

        //------F-------------------

        FixedPoint<2,14> F = 0;
        FixedPoint<2,14> F_xw = 0;
        FixedPoint<2,14> F_yr = 0;

        for(int i=0; i<M_X; i++){
            F_xw += x_input[i] * Weight_F[i];
        }

        for(int i=0; i<M_X; i++){
            F_yr += y_input[i] * Recurrent_F[i];
        }

        F = Fixed_sigmoid(F_xw + F_yr + (C_last*Peephole[1]).convert<2,14>());

        std::cout<<"---------------F--------------"<<std::endl;
        //--------C-----------------
        FixedPoint<2,14> C=0;
        C = (Z*I + C_last*F).convert<2,14>();
        C_last = C;

        //--------O-----------------
        FixedPoint<2,14> O = 0;
        FixedPoint<2,14> O_xw = 0;
        FixedPoint<2,14> O_yr = 0;

        for(int i=0; i<M_X; i++){
            O_xw += x_input[i] * Weight_O[i];
        }

        for(int i=0; i<M_X; i++){
            O_yr += y_input[i] * Recurrent_O[i];
        }

        O = Fixed_sigmoid(O_xw + O_yr + (C*Peephole[2]).convert<2,14>());

        std::cout<<"---------------O--------------"<<std::endl;

        //--------Y----------------------

        FixedPoint<2,14> Y = 0;
        Y = (Fixed_sigmoid(C)*O).convert<2,14>();

        std::cout<<"---------------Y--------------"<<std::endl;

        return Y;
    }
}