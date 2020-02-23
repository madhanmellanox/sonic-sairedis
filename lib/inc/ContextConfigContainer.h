#pragma once

#include "ContextConfig.h"

#include "swss/sal.h"

#include <memory>
#include <map>

namespace sairedis
{
    class ContextConfigContainer
    {
        public:

            ContextConfigContainer();

            virtual ~ContextConfigContainer();

        public:

            void insert(
                    _In_ std::shared_ptr<ContextConfig> contextConfig);

            std::shared_ptr<ContextConfig> get(
                    _In_ uint32_t guid);

        public:

            static std::shared_ptr<ContextConfigContainer> loadFromFile(
                    _In_ const char* contextConfig);

            static std::shared_ptr<ContextConfigContainer> getDefault();

        private:

            std::map<uint32_t, std::shared_ptr<ContextConfig>> m_map;

    };
}
