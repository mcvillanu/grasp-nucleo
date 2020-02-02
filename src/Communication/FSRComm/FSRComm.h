#ifndef FSRCOMM_H
#define FSRCOMM_H
class FSR {
    public:
        /**
         * Default constructor for the FSR.
         **/
        FSR(int pin);

        void setup();

        /**
         * Gets psi from reading voltage of pin
         **/
        float getPSI();

        /**
         * Returns true if psi is above a threshold
         **/
        bool safetyBrake();
    private:
        int pin;
        float brakeThresh = 12; // threshold above which brakes are activated
        float pulldown = 10000; // value of pulldown resistor (in Ohms)
        float curveConst = 9000; // constant given by resistance-pressure curve (1/2 inch medium resistance thrumode) https://www.sensitronics.com/product-res/half-inch-thru-mode-fsr/docs/half-inch-thru-mode-medium-res.pdf
};
#endif