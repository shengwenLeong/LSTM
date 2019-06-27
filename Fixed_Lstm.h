//
// Created by lswmi on 2019/6/27.
//

#ifndef LSTM_FIXED_LSTM_H
#define LSTM_FIXED_LSTM_H

#include <iostream>
#include <vector>
#include "Fixed_Sigmoid.h"
#include "Fixe_Point.h"

#define M_X 4
#define N_Y 4

namespace Fixed_LSTM{

    class Fixed_LSTM{
    private:
        FixedPoint<1,7> C_last;

    public:
        Fixed_LSTM();
        ~Fixed_LSTM();

        FixedPoint<2,14> Fixed_lstm_(std::vector<FixedPoint<1,7>> x_input, std::vector<FixedPoint<1,7>> y_input,
                    std::vector<FixedPoint<1,7>> Weight_Z,std::vector<FixedPoint<1,7>> Weight_I,
                    std::vector<FixedPoint<1,7>> Weight_F,std::vector<FixedPoint<1,7>> Weight_O,
                    std::vector<FixedPoint<1,7>> Recurrent_Z,std::vector<FixedPoint<1,7>> Recurrent_I,
                    std::vector<FixedPoint<1,7>> Recurrent_F,std::vector<FixedPoint<1,7>> Recurrent_O,
                    std::vector<FixedPoint<1,7>> Peephole);

    };
}



#endif //LSTM_FIXED_LSTM_H
