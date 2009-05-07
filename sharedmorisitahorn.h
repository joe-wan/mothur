#ifndef MORHORN_H
#define MORHORN_H
/*
 *  sharedmorisitahorn.h
 *  Mothur
 *
 *  Created by Sarah Westcott on 3/24/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */


#include "calculator.h"

/***********************************************************************/

class MorHorn : public Calculator  {
	
public:
	MorHorn() :  Calculator("MorisitaHorn", 1, false) {};
	EstOutput getValues(SAbundVector*) {return data;};
	EstOutput getValues(vector<SharedRAbundVector*>);
private:
	
};

/***********************************************************************/

#endif
