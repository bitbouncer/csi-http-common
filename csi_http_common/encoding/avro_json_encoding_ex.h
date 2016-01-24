#include <avro/Specific.hh>
#include <avro/Decoder.hh>

#pragma once

//this only works with the bitbouncer branch of avro https://github.com/bitbouncer/avro
//it decodes unions the normal json way (not avro standard)
//useful to decode json data in rest api's

namespace csi
{
    template<class T>
    T& avro_json_decodeEx(const avro::OutputStream& src, T& dst)
    {
        auto mis = avro::memoryInputStream(src);
        avro::DecoderPtr e = avro::jsonDecoderEx(*T::valid_schema()); // bitbouncer specific
        e->init(*mis);
        avro::decode(*e, dst);
        return dst;
    }
}; // csi

