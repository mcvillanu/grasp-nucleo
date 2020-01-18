#ifndef FSR_H
#define FSR_H
class Fsr {
    public:
        /**
         * Default constructor for the FSR.
         **/
        Fsr(int pin);

        void setup();

        /**
         * Gets psi from reading voltage of pin
         **/
        float getPsi();
    private:
        int pin;
        float pulldown = 10000; // value of pulldown resistor (in Ohms)
        float curveConst = 9000; // constant given by resistance-pressure curve (1/2 inch medium resistance thrumode) https://www.sensitronics.com/product-res/half-inch-thru-mode-fsr/docs/half-inch-thru-mode-medium-res.pdf
};
#endif