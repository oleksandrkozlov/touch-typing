#ifndef TOUCH_TYPING_BINARY_STORAGE_HPP
#define TOUCH_TYPING_BINARY_STORAGE_HPP

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <filesystem>
#include <fstream>
#include <utility>

namespace touch_typing {

class BinaryStorage {
public:
    explicit BinaryStorage(std::filesystem::path filename)
        : m_filename{std::move(filename)}
    {
    }

    template<typename Data>
    auto save(const Data& data) -> void
    {
        auto file = std::ofstream{m_filename, std::ios::binary};
        auto archive = boost::archive::text_oarchive{file};
        archive << data;
    }

    template<typename Data>
    [[nodiscard]] auto load() const -> Data
    {
        auto data = Data{};
        auto file = std::ifstream{m_filename, std::ios::binary};
        auto archive = boost::archive::text_iarchive{file};
        archive >> data;
        return data;
    }

private:
    std::filesystem::path m_filename;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_BINARY_STORAGE_HPP
