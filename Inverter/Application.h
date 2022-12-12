/*
 * Application.h
 *
 *  Created on: Dec 11, 2022
 *      Author: Business
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Com.h"

class Application {
public:
  Application();

  void Init();

  void RegisterAllExernalComponents();

  Com *getComObj() { return &com_; }

  void sendTestData();

private:
  Com com_;
};

#endif /* APPLICATION_H_ */
