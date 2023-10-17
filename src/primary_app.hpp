#ifndef __PRIMARY_APP_HPP__
#define __PRIMARY_APP_HPP__

#include "typedefs.hpp"

namespace prim
{
    class PrimaryApp
    {
    private:
        class PrimaryAppImpl;
        unPtr<PrimaryAppImpl> impl;

        void init();
        int mainLoop();

    public:
        PrimaryApp();
        ~PrimaryApp();

        int run();
    };
}


#endif // __PRIMARY_APP_HPP__