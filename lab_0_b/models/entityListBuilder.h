#pragma once

#include "entity.h"
#include <list>

namespace models
{
    class entityListBuilder
    {
        public:
            static list<entity> build(string str);
        private:
            entityListBuilder();
    };
}