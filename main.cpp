#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <fstream>
#include "lstm.h"

std::vector<float> Read_Data(std::string s){
    std::vector<float> results;
    float value;
    std::stringstream ss(s);
    while (ss >> value)
    {
        //std::cout <<value <<std::endl;
        results.push_back(value);
    }
    return results;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::fstream in("../test_data.txt");
    std::string line;



    std::vector<std::vector<float>> input_data;
    std::vector<std::vector<float>> y_data;
    std::vector<std::vector<float>> Weight_Z;
    std::vector<std::vector<float>> Weight_I;
    std::vector<std::vector<float>> Weight_F;
    std::vector<std::vector<float>> Weight_O;

    std::vector<std::vector<float>> Recurrent_Z;
    std::vector<std::vector<float>> Recurrent_I;
    std::vector<std::vector<float>> Recurrent_F;
    std::vector<std::vector<float>> Recurrent_O;

    std::vector<std::vector<float>> Peephole;

    std::vector<std::vector<float>> Result_C;
    std::vector<std::vector<float>> Result_Y;

    int i = 0;

    while (std::getline(in, line))
    {
        if(line.empty() || line.find_first_not_of(' ') == std::string::npos) {
            continue;
        }
        if(line.length()==1){
            continue;
        }
        std::cout<<line.length()<<std::endl;
        if(i<5){
            input_data.push_back(Read_Data(line));
        }else if(i<9){
            Weight_Z.push_back(Read_Data(line));
        }else if(i<13){
            Weight_I.push_back(Read_Data(line));
        }else if(i<17){
            Weight_F.push_back(Read_Data(line));
        }else if(i<21){
            Weight_O.push_back(Read_Data(line));
        }else if(i<25){
            Recurrent_Z.push_back(Read_Data(line));
        }else if(i<29){
            Recurrent_I.push_back(Read_Data(line));
        }else if(i<33){
            Recurrent_F.push_back(Read_Data(line));
        }else if(i<37){
            Recurrent_O.push_back(Read_Data(line));
        }else if(i<41){
            Peephole.push_back(Read_Data(line));
        }else if(i<47){
            Result_C.push_back(Read_Data(line));
        }else{
            Result_Y.push_back(Read_Data(line));
        }
        ++i;
    }

    std::cout <<"======= Content Visual Start ========="<< std::endl;
    for(int i=0; i<4; i++)
    {
        std::cout <<i<<" |";
        for(int j=0; j<3; j++)
            std::cout << Peephole[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout <<"======= Content Visual END ========="<< std::endl;

    y_data.resize(6);
    for(int i=0; i<6; i++){
        y_data[i].resize(6);
    }
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
            y_data[i][j] = 0;
    }

    std::cout <<"======= start ========="<< std::endl;
    std::vector<LSTM::LSTM> pLstm;

    pLstm.resize(N_Y);

    std::vector<float> R_Y;
    float Y_temp;

    for(int t=0; t<5; t++){ //time
        for(int n=0; n<N_Y; n++){ //N_Y direction
            y_data[t+1][n] = pLstm[n].lstm_(input_data[t],y_data[t],
                    Weight_Z[n],Weight_I[n],
                    Weight_F[n],Weight_O[n],
                    Recurrent_Z[n],Recurrent_I[n],
                    Recurrent_F[n],Recurrent_O[n],
                    Peephole[n]);
            std::cout<<Y_temp<<std::endl;
        }
    }

    for(int i=0; i<6; i++)
    {
        std::cout<<std::endl;
        for(int j=0; j<4; j++)
            std::cout<<y_data[i][j] <<" ";
    }
    std::cout<<std::endl;
    std::cout <<"======= Finish ========="<< std::endl;
    return 0;
}