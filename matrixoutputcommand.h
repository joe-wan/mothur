#ifndef MATRIXOUTPUTCOMMAND_H
#define MATRIXOUTPUTCOMMAND_H

/*
 *  matrixoutputcommand.h
 *  Mothur
 *
 *  Created by Sarah Westcott on 5/20/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */ 
#include "command.hpp"
#include "inputdata.h"
#include "groupmap.h"
#include "readotu.h"
#include "validcalculator.h"

// aka. dist.shared()

/* This command create a tree file for each similarity calculator at distance level, using various calculators to find the similiarity between groups. 
	The user can select the lines or labels they wish to use as well as the groups they would like included.
	They can also use as many or as few calculators as they wish. */
	
class GlobalData;

class MatrixOutputCommand : public Command {
	
public:
	MatrixOutputCommand(string);	
	~MatrixOutputCommand();
	int execute();	
	void help();
	
private:
	void printSims(ostream&);
	void process(vector<SharedRAbundVector*>);
	
	GlobalData* globaldata;
	ReadOTUFile* read;
	vector<Calculator*> matrixCalculators;
	vector< vector<float> > simMatrix;
	InputData* input;
	ValidCalculators* validCalculator;
	vector<SharedRAbundVector*> lookup;
	string exportFileName;
	int numGroups;
	ofstream out;

	bool abort, allLines;
	set<int> lines; //hold lines to be used
	set<string> labels; //holds labels to be used
	string outputFile, calc, groups, line, label;
	vector<string>  Estimators, Groups; //holds estimators to be used
	

};
	
	
#endif
