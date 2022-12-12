/*
 * ApplicationSetup.cpp
 *
 *  Created on: Dec 11, 2022
 *      Author: Business
 */
#include "ApplicationSetup.h"

Application application_;

void ApplicationSetup(void) {
  application_.RegisterAllExernalComponents();
  application_.Init();
}
