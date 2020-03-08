#ifndef MOTOR_H
#define MOTOR_H

class FSRMatrix {
    public:
        const int FSR_MATRIX_ROW_COUNT = 7;
        const int FSR_MATRIX_COLUMN_COUNT = 11;
        const int ROWS_PER_MUX = 8;
        const int MUX_COUNT = 1;
        const int CHANNEL_PINS_PER_MUX = 3;

        /**
         * Default constructor for the FSR Matrix.
         **/
        FSRMatrix();

        /**
         * Reads the entire FSR matrix and transfers the values via serial connection
         **/
    
        void read();
    private:
        int numReadings = 500;                   //keeps track of how many readings you'd like to take before writing the file.
        int readingCounter = 0;                  //c
        int current_enabled_mux = MUX_COUNT - 1; //init to number of last mux so enabled mux increments to first mux on first scan.


        /*
        * Function: shiftColumn
        * ----------------------------
        *   parameter1: boolean value that indicates transition to next shift register IC
        *   returns: void
        */
        void shiftColumn(bool isFirst);

        /*
        * Function: setRow
        * ----------------------------
        *   parameter1: the row number
        *   returns: void
        */
        void setRow(int rowNumber);

        /**
         * Sets all FSR matrix pins to desired inputs and outputs
         **/
        void initPins();

};
#endif