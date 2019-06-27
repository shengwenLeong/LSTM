//
// Created by lswmi on 2019/6/27.
//

#include "Fixed_Sigmoid.h"
#include <stdio.h>
#include <math.h>

// sigmoid関数
FixedPoint<2,14> Fixed_sigmoid(FixedPoint<2,14> x){
    float temp;
    temp = FixedPoint<2,14>(x).getValueF();
    FixedPoint<2,14> result;
    result = (1 / (1 + exp(-temp)));
    return result;
}