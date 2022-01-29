/* Copyright (c) 2012 Cheese and Bacon Games, LLC */
/* This file is licensed under the MIT License. */
/* See the file docs/LICENSE.txt for the full license text. */

#include "need.h"
#include "game_constants.h"

using namespace std;

Need::Threshold Need::getThreshold (const Health need, const Health maximumNeed) {
    double proportion = (double) need / (double) maximumNeed;

    if (proportion >= Game_Constants::NEED_THRESHOLD_GREAT) {
        return Threshold::great;
    } else if (proportion >= Game_Constants::NEED_THRESHOLD_GOOD) {
        return Threshold::good;
    } else if (proportion >= Game_Constants::NEED_THRESHOLD_OK) {
        return Threshold::ok;
    } else if (proportion >= Game_Constants::NEED_THRESHOLD_BAD) {
        return Threshold::bad;
    } else {
        return Threshold::terrible;
    }
}
