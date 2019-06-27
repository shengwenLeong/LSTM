//
// Created by lswmi on 2019/6/26.
//

#ifndef LSTM_LSTM_H
#define LSTM_LSTM_H

#include <iostream>
#include <vector>
#include "sigmoid.h"

#define M_X 4
#define N_Y 4

namespace LSTM{

    class LSTM{
    private:
        float C_last;

    public:
        LSTM();
        ~LSTM();

        float lstm_(std::vector<float> x_input, std::vector<float> y_input,
                        std::vector<float> Weight_Z,std::vector<float> Weight_I,
                        std::vector<float> Weight_F,std::vector<float> Weight_O,
                        std::vector<float> Recurrent_Z,std::vector<float> Recurrent_I,
                        std::vector<float> Recurrent_F,std::vector<float> Recurrent_O,
                        std::vector<float> Peephole);

    };
}




#endif //LSTM_LSTM_H
