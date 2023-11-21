#include "button.h"
int KeyReg0_1 = NORMAL_STATE;
int KeyReg1_1 = NORMAL_STATE;
int KeyReg2_1 = NORMAL_STATE;
int KeyReg3_1 = NORMAL_STATE;

int KeyReg0_2 = NORMAL_STATE;
int KeyReg1_2 = NORMAL_STATE;
int KeyReg2_2 = NORMAL_STATE;
int KeyReg3_2 = NORMAL_STATE;

int KeyReg0_3 = NORMAL_STATE;
int KeyReg1_3 = NORMAL_STATE;
int KeyReg2_3 = NORMAL_STATE;
int KeyReg3_3 = NORMAL_STATE;

int TimeOutForKeyPress1 =  100;
int TimeOutForKeyPress2 =  100;
int TimeOutForKeyPress3 =  100;

int button1_flag = 0;
int button2_flag=0;
int button3_flag=0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void subKey1Process(){
	button1_flag = 1;
}
void subKey2Process(){
	button2_flag = 1;
}
void subKey3Process(){
	button3_flag = 1;
}

void getKeyInput(){
//	BUTTON1
  KeyReg2_1 = KeyReg1_1;
  KeyReg1_1 = KeyReg0_1;
  KeyReg0_1 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);

  if ((KeyReg1_1 == KeyReg0_1) && (KeyReg1_1 == KeyReg2_1)){
    if (KeyReg2_1 != KeyReg3_1){
    	KeyReg3_1 = KeyReg2_1;

      if (KeyReg3_1 == PRESSED_STATE){
        TimeOutForKeyPress1 = 100;
        subKey1Process();
      }

    }else if(KeyReg3_1==PRESSED_STATE){
       TimeOutForKeyPress1 --;
        if (TimeOutForKeyPress1 == 0){
        	TimeOutForKeyPress1 = 100;
			subKey1Process();
        }
    }
  }

//  BUTTON2
	KeyReg2_2 = KeyReg1_2;
	KeyReg1_2 = KeyReg0_2;
	KeyReg0_2 = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);

	if ((KeyReg1_2 == KeyReg0_2) && (KeyReg1_2 == KeyReg2_2)){
	  if (KeyReg2_2 != KeyReg3_2){
		KeyReg3_2 = KeyReg2_2;

		if (KeyReg3_2 == PRESSED_STATE){
		  TimeOutForKeyPress2 = 100;
		  subKey2Process();
		}
	  }else if(KeyReg3_2==PRESSED_STATE){
		 TimeOutForKeyPress2 --;
		  if (TimeOutForKeyPress2 == 0){
			TimeOutForKeyPress2 = 100;
			subKey2Process();
		  }
	  }
	}

//	BUTTON3
	KeyReg2_3 = KeyReg1_3;
	KeyReg1_3 = KeyReg0_3;
	KeyReg0_3 = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

	if ((KeyReg1_3 == KeyReg0_3) && (KeyReg1_3 == KeyReg2_3)){
	  if (KeyReg2_3 != KeyReg3_3){
		KeyReg3_3 = KeyReg2_3;

		if (KeyReg3_3 == PRESSED_STATE){
		  TimeOutForKeyPress3 = 100;
		  subKey3Process();
		}
	  }else if(KeyReg3_3==PRESSED_STATE){
		 TimeOutForKeyPress3 --;
		  if (TimeOutForKeyPress3 == 0){
			TimeOutForKeyPress3 = 100;
			subKey3Process();
		  }
	  }
	}
}

