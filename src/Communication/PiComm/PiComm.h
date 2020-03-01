#ifndef PICOMM_H
#define PICOMM_H

#include <stdlib.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <Utilities/Miscellaneous/Miscellaneous.h>
#include <Utilities/Constants.h>



class Pi {
    private:
        static bool serialActive;

    public:
        Pi();

        static void setup();
        static void destroy();

        static String const read();
        static void write(String const & str);

        static void refresh();
        static void reset();

        static bool const isSerialActive();
};

#endif