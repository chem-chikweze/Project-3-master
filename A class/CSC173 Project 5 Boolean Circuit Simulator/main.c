/*
 * File: main.c
 * Creator: George Ferguson
 * Created: Mon Nov 28 14:11:17 2016
 * Time-stamp: <Tue Jul 17 16:02:29 EDT 2018 ferguson>
 */
#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"
#include <math.h>

int ret(int r, int c){
	int row = r;
	int col = c;
	int mod = row % (int) round(pow(2, col));
	if(mod != 0){
		return (int) (((row-mod)/(int) pow(2,col)) + 1)%2;
	} else {
		return (int) ((row)/ (int) pow(2,col))%2;
	}
}
/**
 * Two AND gates connected to make a 3-input AND circuit.
 */
static Circuit* and3_Circuit() {
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean* z = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A1 = new_AndGate();
	Gate* A2 = new_AndGate();
	Gate** gates = new_Gate_array(2);
	gates[0] = A1;
	gates[1] = A2;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 2, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2, 0));
	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(A2), out);
	return circuit;
}

static char* b2s(bool b) {
	return b ? "T" : "F";
}

static void test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2) {
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_setInput(circuit, 2, in2);
	Circuit_update(circuit);
	bool out0 = Circuit_getOutput(circuit, 0);
	printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
}

static void test2In1Out(Circuit* circuit, bool in0, bool in1) {
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_update(circuit);
	bool out0 = Circuit_getOutput(circuit, 0);
	printf("%s %s -> %s\n", b2s(in0), b2s(in1), b2s(out0));
}

static void test3In2Out(Circuit* circuit, bool in0, bool in1, bool in2) {
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_setInput(circuit, 2, in2);
	Circuit_update(circuit);
	bool out0 = Circuit_getOutput(circuit, 0);
	bool out1 = Circuit_getOutput(circuit, 1);
	printf("%s %s %s -> %s %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0), b2s(out1));
}


static Circuit* first(){
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(2);
	inputs[0] = x;
	inputs[1] = y;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A1 = new_NAndGate();
	Gate* A2 = new_OrGate();	
	Gate* A3 = new_AndGate();
	Gate** gates = new_Gate_array(3);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;

	Circuit *circuit = new_Circuit(2, inputs, 1, outputs, 3, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
	Circuit_connect(circuit, x, Gate_getInput(A2, 0));
	Circuit_connect(circuit, y, Gate_getInput(A2, 1));

	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A3, 1));

	Circuit_connect(circuit, Gate_getOutput(A3), out);
	return circuit;
}

static Circuit* second(){
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean* z = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A1 = new_AndGate();
	Gate* A2 = new_NAndGate();	
	Gate* A3 = new_OrGate();
	Gate** gates = new_Gate_array(3);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 3, gates);
	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
	Circuit_connect(circuit, y, Gate_getInput(A2, 0));
	Circuit_connect(circuit, z, Gate_getInput(A2, 1));

	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A3, 1));

	Circuit_connect(circuit, Gate_getOutput(A3), out);
	return circuit;
}

static Circuit* third(){
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean* z = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A1 = new_Inverter();
	Gate* A2 = new_Inverter();
	Gate* A3 = new_Inverter();

	Gate* A4 = new_AndGate();
	Gate* A5 = new_AndGate();	
	Gate* A6 = new_AndGate();

	Gate* A7 = new_OrGate();
	Gate* A8 = new_OrGate();

	Gate** gates = new_Gate_array(8);
	gates[0] = A1;
	gates[1] = A2;
	gates[2] = A3;	
	gates[3] = A4;
	gates[4] = A5;
	gates[5] = A6;
	gates[6] = A7;
	gates[7] = A8;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 8, gates);
	Circuit_connect(circuit, y, Gate_getInput(A1, 0));
	Circuit_connect(circuit, z, Gate_getInput(A2, 0));
	Circuit_connect(circuit, x, Gate_getInput(A3, 0));

	Circuit_connect(circuit, x, Gate_getInput(A4, 0));
	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A4, 1));
	Circuit_connect(circuit, y, Gate_getInput(A5, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A5, 1));
	Circuit_connect(circuit, z, Gate_getInput(A6, 0));
	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A6, 1));
	
	Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(A7, 0));
	Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(A7, 1));

	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(A8, 0));
	Circuit_connect(circuit, Gate_getOutput(A6), Gate_getInput(A8, 1));

	Circuit_connect(circuit, Gate_getOutput(A8), out);
	return circuit;
}

static Circuit* oneBitAdder(){
	Boolean* x = new_Boolean(false);
	Boolean* y = new_Boolean(false);
	Boolean* c = new_Boolean(false);
	Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = c;

	Boolean* z = new_Boolean(false);
	Boolean* d = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(2);
	outputs[0] = z;
	outputs[1] = d;

	Gate* B1 = new_Inverter();
	Gate* B2 = new_Inverter();
	Gate* B3 = new_Inverter();

	Gate* A1 = new_And3Gate();
	Gate* A2 = new_And3Gate();
	Gate* A3 = new_And3Gate();
	Gate* A4 = new_And3Gate();
	Gate* A5 = new_And3Gate();
	Gate* A6 = new_And3Gate();
	Gate* A7 = new_And3Gate();

	Gate* C1 = new_Or4Gate();
	Gate* C2 = new_Or4Gate();

	Gate** gates = new_Gate_array(12);
	gates[0] = B1;
	gates[1] = B2;
	gates[2] = B3;	

	gates[3] = A1;
	gates[4] = A2;
	gates[5] = A3;	
	gates[6] = A4;
	gates[7] = A5;
	gates[8] = A6;
	gates[9] = A7;

	gates[10] = C1;
	gates[11] = C2;

	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 12, gates);
	Circuit_connect(circuit, x, Gate_getInput(B1, 0));
	Circuit_connect(circuit, y, Gate_getInput(B2, 0));
	Circuit_connect(circuit, z, Gate_getInput(B3, 0));

	Circuit_connect(circuit, Gate_getOutput(B1), Gate_getInput(A1, 0));
	Circuit_connect(circuit, Gate_getOutput(B2), Gate_getInput(A1, 1));
	Circuit_connect(circuit, c, Gate_getInput(A1, 2));

	Circuit_connect(circuit, Gate_getOutput(B1), Gate_getInput(A2, 0));
	Circuit_connect(circuit, y, Gate_getInput(A2, 1));
	Circuit_connect(circuit, Gate_getOutput(B3), Gate_getInput(A2, 2));

	Circuit_connect(circuit, Gate_getOutput(B1), Gate_getInput(A3, 0));
	Circuit_connect(circuit, y, Gate_getInput(A3, 1));
	Circuit_connect(circuit, c, Gate_getInput(A3, 2));

	Circuit_connect(circuit, x, Gate_getInput(A4, 0));
	Circuit_connect(circuit, Gate_getOutput(B2), Gate_getInput(A4, 1));
	Circuit_connect(circuit, Gate_getOutput(B3), Gate_getInput(A4, 2));

	Circuit_connect(circuit, x, Gate_getInput(A5, 0));
	Circuit_connect(circuit, Gate_getOutput(B2), Gate_getInput(A5, 1));
	Circuit_connect(circuit, c, Gate_getInput(A5, 2));

	Circuit_connect(circuit, Gate_getOutput(B3), Gate_getInput(A6, 0));
	Circuit_connect(circuit, y, Gate_getInput(A6, 1));
	Circuit_connect(circuit, x, Gate_getInput(A6, 2));

	Circuit_connect(circuit, x, Gate_getInput(A7, 0));
	Circuit_connect(circuit, y, Gate_getInput(A7, 1));
	Circuit_connect(circuit, c, Gate_getInput(A7, 2));

	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(C1, 0));
	Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(C1, 1));	
	Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(C1, 2));
	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(C1, 3));

	Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(C2, 0));
	Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(C2, 1));	
	Circuit_connect(circuit, Gate_getOutput(A6), Gate_getInput(C2, 2));
	Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(C2, 3));

	Circuit_connect(circuit, Gate_getOutput(C1), z);
	Circuit_connect(circuit, Gate_getOutput(C2), d);
	return circuit;
}



int main(int argc, char **argv) {

	Circuit*  circuit = first();
	printf("First Circuit:\n");
	Circuit_dump(circuit);
	printf("Testing First Circuit\n");
	printf("Chem: Some input(s) false: should be false\n");
	for(int row = 0; row< 4; row++){
		test2In1Out(circuit, ret(row, 0)%2, ret(row, 1)%2);
	}
	Circuit_free(circuit);
	printf("\n");


	circuit = second();
	printf("Second Circuit\n");
	Circuit_dump(circuit);
	printf("Testing Second Circuit\n");
	printf("Testing: Some input(s) false: should be false\n");
	for(int row = 0; row< 8; row++){
		test3In1Out(circuit, ret(row, 0)%2, ret(row, 1)%2, ret(row, 2)%2);
	}
	Circuit_free(circuit);
	printf("\n");


	circuit = third();
	printf("Third Circuit\n");
	Circuit_dump(circuit);
	printf("Testing Third Circuit\n");
	printf("Testing: Some input(s) false: should be false\n");
	for(int row = 0; row< 8; row++){
		test3In1Out(circuit, ret(row, 0)%2, ret(row, 1)%2, ret(row, 2)%2);
	}
	Circuit_free(circuit);
	printf("\n");

	circuit = oneBitAdder();
	printf("One Bit Adder Circuit\n");
	Circuit_dump(circuit);
	printf("Testing the One Bit Adder Circuit\n");
	printf("Testing: Some input(s) false: should be false\n");
	for(int row = 0; row< 8; row++){
		test3In2Out(circuit, ret(row, 0)%2, ret(row, 1)%2, ret(row, 2)%2);
	}
	Circuit_free(circuit);
	printf("\n");

}
