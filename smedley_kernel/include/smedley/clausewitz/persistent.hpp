#pragma once

#include "reader.hpp"
#include "writer.hpp"

namespace smedley::clausewitz
{

    /**
     * The base class for most persistent data in the program. This includes virtually all
     * data which is stored in the game files. Definition files in the common dir, decisions,
     * events, history, etc.
     */
    class CPersistent
    {
    protected:
        int _type_token;
    public:
        virtual ~CPersistent();
        /// @brief Write the entire object to the provided CWriter object
        virtual void Write(CWriter &);
        virtual void WriteMembers(CWriter &);
        /// @brief Deserialize the object from the provided CReader.
        virtual void Read(CReader &);
        /// @brief Deserialize the specified member
        /// @param reader the reader to read from
        /// @param type the type token of the member to be deserialized
        virtual void ReadMember(CReader &reader, int type);
        /// @brief Initializes the object after deserialization. Called at the end of CPersistent::Read
        virtual void InitPostRead();
    };

    static_assert(sizeof(CPersistent) == 0x8);

}