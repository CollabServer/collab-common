#pragma once

#include <string>
#include <msgpack.hpp>

#include "collabcommon/messaging/Message.h"
#include "collabcommon/messaging/MessageFactory.h"

namespace collab {


/**
 * \brief
 * Message for debug purpose
 */
class MsgDebug : public Message {
    private:
        std::string _content;

    public:
        bool serialize(std::stringstream& buffer) const override {
            msgpack::pack(buffer, _content);
            return true;
        }

        bool unserialize(std::stringstream& buffer) override {
            const char* data    = buffer.str().data();
            const size_t size   = buffer.str().size();

            msgpack::unpacked r1;
            msgpack::unpack(r1, data, size);
            r1.get().convert(_content);

            return true;
        }

        int getType() const override {
            return MessageFactory::MSG_DEBUG;
        }

    public:
        void setcontent(const std::string& str) {
            _content = str;
        }

        const std::string& content() const {
            return _content;
        }
};


} // End namespace


