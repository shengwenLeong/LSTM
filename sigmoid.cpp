//
// Created by lswmi on 2019/6/26.
//

#include "sigmoid.h"
#include <stdio.h>
#include <math.h>
#include "sigmoid.h"

// sigmoid関数
float sigmoid(float x){
    return (1 / (1 + exp(-x)));
}