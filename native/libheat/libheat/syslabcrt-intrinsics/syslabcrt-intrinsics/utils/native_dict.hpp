#ifndef SYSLAB_CC_RUNTIME_INTRINSICS_NDICT_HPP
#define SYSLAB_CC_RUNTIME_INTRINSICS_NDICT_HPP

#include "syslabcrt-intrinsics/declarations/mod.hpp" // IWYU pragma: export

#include <cstdint>
#include <unordered_map>

namespace syslab
{
namespace rt
{

template <typename T>
static typename std::enable_if<!std::is_same<T, u8string_t>::value, size_t>::type genericHash(const T &t)
{
    size_t hash = 0;
    const uint8_t *p = (const uint8_t *)&t;
    for (size_t i = 0; i < sizeof(T); i++)
    {
        hash = (hash << 5) - hash + p[i];
    }
    return hash;
}

template <typename T>
static typename std::enable_if<std::is_same<T, u8string_t>::value, size_t>::type genericHash(const T &t)
{
    return std::hash<u8string_t>{}(t);
}

// TODO(-): HashMap implementation
template <typename Key> struct KeyHash
{
    std::size_t (*fn)(const Key &k);
    std::size_t operator()(const Key &k) const
    {
        if (fn == nullptr)
        {
            return genericHash<Key>(k);
        }
        else
        {
            return fn(k);
        }
    }
};

template <typename Key> struct KeyEqual
{
    bool (*fn)(const Key &lhs, const Key &rhs);
    bool operator()(const Key &lhs, const Key &rhs) const CXX20_REQUIRES(std::equality_comparable<Key>)
    {
        if (fn == nullptr)
        {
            return lhs == rhs;
        }
        else
        {
            return fn(lhs, rhs);
        }
    }
};

// TODO(-): fix cumtom hash function
// template <typename K, typename V> static void *CreateMap(void *hash, void *eq)
// {
//     using KeyHash_t = std::size_t (*)(const K &);
//     using KeyEqual_t = bool (*)(const K &, const K &);
//     KeyHash<K> hashFn = KeyHash<K>{reinterpret_cast<KeyHash_t>(hash)};
//     KeyEqual<K> eqFn = KeyEqual<K>{reinterpret_cast<KeyEqual_t>(eq)};
//     std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>> *map;
//     map = new std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>>(10, hashFn, eqFn);
//     return reinterpret_cast<void *>(map);
// }

template <typename K, typename V> static void *CreateMap()
{
    using KeyHash_t = std::size_t (*)(const K &);
    using KeyEqual_t = bool (*)(const K &, const K &);

    KeyHash<K> hashFn = KeyHash<K>{nullptr};
    KeyEqual<K> eqFn = KeyEqual<K>{nullptr};
    std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>> *map;
    map = new std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>>(10, hashFn, eqFn);
    return reinterpret_cast<void *>(map);
}

template <typename K, typename V> static void DeleteMap(void *map)
{
    if (map == nullptr)
    {
        return;
    }
    std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>> *m;
    m = reinterpret_cast<std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>> *>(map);
    delete m;
    return;
}

template <typename K, typename V> static bool MapTryGetValue(void *map, const K &key, V *value)
{
    if (map == nullptr)
    {
        return false;
    }
    std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>> *m;
    m = reinterpret_cast<std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>> *>(map);
    if (m->find(key) != m->end())
    {
        *value = m->at(key);
        return true;
    }
    else
    {
        return false;
    }
}

template <typename K, typename V> static void MapInsert(void *map, const K &key, const V &value)
{
    if (map == nullptr)
    {
        return;
    }
    std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>> *m;
    m = reinterpret_cast<std::unordered_map<K, V, KeyHash<K>, KeyEqual<K>> *>(map);
    m->insert(std::make_pair(key, value));
}

} // namespace rt
} // namespace syslab

#endif