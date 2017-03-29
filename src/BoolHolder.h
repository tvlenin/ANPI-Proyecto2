/*
 * BoolHolder.h
 *
 *  Created on: Mar 28, 2017
 *      Author: fasm22
 */

#ifndef SRC_BOOLHOLDER_H_
#define SRC_BOOLHOLDER_H_

class BoolHolder{
public:
	BoolHolder(bool pState){
		state = pState;
	}
	bool GetState() const { return state; } // read only
	//bool& GetState() { return *state; } // read/write
	void SetState(bool pState){
		state = pState;
	}

private:
	bool state;
};



#endif /* SRC_BOOLHOLDER_H_ */
