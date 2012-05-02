/*
 *  readdistcommand.cpp
 *  Mothur
 *
 *  Created by Sarah Westcott on 1/20/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "readdistcommand.h"
#include "readphylip.h"
#include "readcolumn.h"
#include "readmatrix.hpp"

//**********************************************************************************************************************
ReadDistCommand::ReadDistCommand(string option) {
	try {
		abort = false; calledHelp = false;   
		
		//allow user to run help
		if(option == "help") { help(); abort = true; calledHelp = true; }
		else if(option == "citation") { citation(); abort = true; calledHelp = true;}
		
		else {
			/*//valid paramters for this command
			string Array[] =  {"phylip", "column", "name", "cutoff", "precision", "group","outputdir","inputdir","sim"};
			vector<string> myArray (Array, Array+(sizeof(Array)/sizeof(string)));
			
			OptionParser parser(option);
			map<string, string> parameters = parser.getParameters();
			
			ValidParameters validParameter;
			map<string,string>::iterator it;
		
			//check to make sure all parameters are valid for command
			for (it = parameters.begin(); it != parameters.end(); it++) { 
				if (validParameter.isValidParameter(it->first, myArray, it->second) != true) {  abort = true;  }
			}
			
			globaldata->newRead();
			
			//if the user changes the input directory command factory will send this info to us in the output parameter 
			string inputDir = validParameter.validFile(parameters, "inputdir", false);		
			if (inputDir == "not found"){	inputDir = "";		}
			else {
				string path;
				it = parameters.find("phylip");
				//user has given a template file
				if(it != parameters.end()){ 
					path = m->hasPath(it->second);
					//if the user has not given a path then, add inputdir. else leave path alone.
					if (path == "") {	parameters["phylip"] = inputDir + it->second;		}
				}
				
				it = parameters.find("column");
				//user has given a template file
				if(it != parameters.end()){ 
					path = m->hasPath(it->second);
					//if the user has not given a path then, add inputdir. else leave path alone.
					if (path == "") {	parameters["column"] = inputDir + it->second;		}
				}
				
				it = parameters.find("name");
				//user has given a template file
				if(it != parameters.end()){ 
					path = m->hasPath(it->second);
					//if the user has not given a path then, add inputdir. else leave path alone.
					if (path == "") {	parameters["name"] = inputDir + it->second;		}
				}
				
				it = parameters.find("group");
				//user has given a template file
				if(it != parameters.end()){ 
					path = m->hasPath(it->second);
					//if the user has not given a path then, add inputdir. else leave path alone.
					if (path == "") {	parameters["group"] = inputDir + it->second;		}
				}
			}

			//if the user changes the output directory command factory will send this info to us in the output parameter 
			outputDir = validParameter.validFile(parameters, "outputdir", false);		if (outputDir == "not found"){	outputDir = "";	}

			//check for required parameters
			phylipfile = validParameter.validFile(parameters, "phylip", true);
			if (phylipfile == "not open") { abort = true; }
			else if (phylipfile == "not found") { phylipfile = ""; }	
			else {  globaldata->setPhylipFile(phylipfile);  globaldata->setFormat("phylip"); 	}
			
			columnfile = validParameter.validFile(parameters, "column", true);
			if (columnfile == "not open") { abort = true; }	
			else if (columnfile == "not found") { columnfile = ""; }
			else {  globaldata->setColumnFile(columnfile); globaldata->setFormat("column");	}
			
			groupfile = validParameter.validFile(parameters, "group", true);
			if (groupfile == "not open") { abort = true; }	
			else if (groupfile == "not found") { groupfile = ""; }
			else {  
				globaldata->setGroupFile(groupfile); 
				//groupMap = new GroupMap(groupfile);
				//groupMap->readMap();
			}

			namefile = validParameter.validFile(parameters, "name", true);
			if (namefile == "not open") { abort = true; }	
			else if (namefile == "not found") { namefile = ""; }
			else {  globaldata->setNameFile(namefile);	}
			
			//you are doing a list and group shared
			if ((phylipfile != "") && (groupfile != "")) { 
			globaldata->setFormat("matrix"); }
			
			if ((phylipfile == "") && (columnfile == "")) { m->mothurOut("When executing a read.dist command you must enter a phylip or a column."); m->mothurOutEndLine(); abort = true; }
			else if ((phylipfile != "") && (columnfile != "")) { m->mothurOut("When executing a read.dist command you must enter ONLY ONE of the following: phylip or column."); m->mothurOutEndLine(); abort = true; }
		
			if (columnfile != "") {
				if (namefile == "") {  cout << "You need to provide a namefile if you are going to use the column format." << endl; abort = true; }
			}
			
			//check for optional parameter and set defaults
			// ...at some point should added some additional type checking...
			//get user cutoff and precision or use defaults
			string temp;
			temp = validParameter.validFile(parameters, "precision", false);		if (temp == "not found") { temp = "100"; }
			m->mothurConvert(temp, precision); 
			
			temp = validParameter.validFile(parameters, "sim", false);				if (temp == "not found") { temp = "F"; }
			sim = m->isTrue(temp); 
			globaldata->sim = sim;
			
			temp = validParameter.validFile(parameters, "cutoff", false);			if (temp == "not found") { temp = "10"; }
			convert(temp, cutoff); 
			cutoff += (5 / (precision * 10.0)); 
			
			if (abort == false) {
				distFileName = globaldata->inputFileName;
				format = globaldata->getFormat();	
		
				if (format == "column") { read = new ReadColumnMatrix(distFileName); }	
				else if (format == "phylip") { read = new ReadPhylipMatrix(distFileName); }
				else if (format == "matrix") { 
					groupMap = new GroupMap(groupfile);
					int error = groupMap->readMap();
					if (error == 1) { delete groupMap; abort = true; }
					else {
						if (globaldata->gGroupmap != NULL) { delete globaldata->gGroupmap;  }
						globaldata->gGroupmap = groupMap;
					}
				}
		
				if (format != "matrix" ) {
					read->setCutoff(cutoff);
	
					if(namefile != ""){	
						nameMap = new NameAssignment(namefile);
						nameMap->readMap();
					}else{
						nameMap = NULL;
					}
				}
			}
*/
		}

	}
	catch(exception& e) {
		m->errorOut(e, "ReadDistCommand", "ReadDistCommand");
		exit(1);
	}
}
//**********************************************************************************************************************
int ReadDistCommand::execute(){
	try {
		
		if (abort == true) { if (calledHelp) { return 0; }  return 2;	}
		m->mothurOut(getHelpString()); m->mothurOutEndLine();
/*
		time_t start = time(NULL);
		size_t numDists = 0;
		
		if (format == "matrix") {
			ifstream in;
			m->openInputFile(distFileName, in);
			matrix = new FullMatrix(in); //reads the matrix file
			in.close();
			
			if (m->control_pressed) { delete groupMap; delete matrix; return 0; }
			
			//if files don't match...
			if (matrix->getNumSeqs() < groupMap->getNumSeqs()) {  
				m->mothurOut("Your distance file contains " + toString(matrix->getNumSeqs()) + " sequences, and your group file contains " + toString(groupMap->getNumSeqs()) + " sequences.");  m->mothurOutEndLine();				
				//create new group file
				if(outputDir == "") { outputDir += m->hasPath(groupfile); }
				
				string newGroupFile = outputDir + m->getRootName(m->getSimpleName(groupfile)) + "editted.groups";
				outputNames.push_back(newGroupFile);
				ofstream outGroups;
				m->openOutputFile(newGroupFile, outGroups);
				
				for (int i = 0; i < matrix->getNumSeqs(); i++) {
					if (m->control_pressed) { delete groupMap; delete matrix; outGroups.close(); m->mothurRemove(newGroupFile); return 0; }
					
					Names temp = matrix->getRowInfo(i);
					outGroups << temp.seqName << '\t' << temp.groupName << endl;
				}
				outGroups.close();
				
				m->mothurOut(newGroupFile + " is a new group file containing only the sequence that are in your distance file. I will read this file instead."); m->mothurOutEndLine();
				
				//read new groupfile
				delete groupMap; groupMap = NULL;
				groupfile = newGroupFile;
				globaldata->setGroupFile(groupfile); 
				
				groupMap = new GroupMap(groupfile);
				groupMap->readMap();
				
				if (m->control_pressed) { delete groupMap; delete matrix; m->mothurRemove(newGroupFile); return 0; }
	
				globaldata->gGroupmap = groupMap;
			}
			
			//memory leak prevention
			if (globaldata->gMatrix != NULL) { delete globaldata->gMatrix;  }
			globaldata->gMatrix = matrix; //save matrix for coverage commands
			numDists = matrix->getSizes()[1];
		} else {
			read->read(nameMap);
			//to prevent memory leak
			
			if (m->control_pressed) {  return 0; }
		
			if (globaldata->gListVector != NULL) {  delete globaldata->gListVector;  }
			globaldata->gListVector = read->getListVector();

			if (globaldata->gSparseMatrix != NULL) { delete globaldata->gSparseMatrix;  }
			globaldata->gSparseMatrix = read->getMatrix();
			numDists = globaldata->gSparseMatrix->getNNodes();
		}
		
		if (m->control_pressed) {  return 0; }

		if (outputNames.size() != 0) {
			m->mothurOutEndLine();
			m->mothurOut("Output File Name: "); m->mothurOutEndLine();
			for (int i = 0; i < outputNames.size(); i++) {	m->mothurOut(outputNames[i]); m->mothurOutEndLine();	}
			m->mothurOutEndLine();
		}
		
		m->mothurOut("It took " + toString(time(NULL) - start) + " secs to read "); m->mothurOutEndLine();
 */
		return 0;
		
	}
	catch(exception& e) {
		m->errorOut(e, "ReadDistCommand", "execute");
		exit(1);
	}
}