//
// Created by nhisoka on 5/6/2024.
//

#include "Scanner.hpp"

#define IS_IN_RANGE( value, max, min ) ( value >= max && value <= min )
#define GET_BITS( value ) ( IS_IN_RANGE( value, '0', '9' ) ? ( value - '0' ) : ( ( value & ( ~0x20 ) ) - 'A' + 0xA ) )
#define GET_BYTE( value ) ( GET_BITS( value[0] ) << 4 | GET_BITS( value[1] ) )

Scanner* Scanner::m_pSingleton = nullptr;

Scanner* Scanner::get_singleton() {
    if (m_pSingleton == nullptr)
        m_pSingleton = new Scanner();
    return m_pSingleton;
}

std::uintptr_t Scanner::scan(const std::string& signature) {
    auto image = reinterpret_cast<std::uintptr_t>(GetModuleHandleA("RobloxStudioBeta.exe"));
    if (!image)
        return 0u;

    auto image_base = static_cast<std::uintptr_t>(image);
    auto image_dos_hdr = reinterpret_cast<IMAGE_DOS_HEADER*>(image_base);
    if (image_dos_hdr->e_magic != IMAGE_DOS_SIGNATURE)
        return 0u;

    auto image_nt_hdrs = reinterpret_cast<IMAGE_NT_HEADERS*>(image_base + image_dos_hdr->e_lfanew);
    if (image_nt_hdrs->Signature != IMAGE_NT_SIGNATURE)
        return 0u;

    auto scan_begin = reinterpret_cast<std::uint8_t*>(image_base);
    auto scan_end = scan_begin + image_nt_hdrs->OptionalHeader.SizeOfImage;

    std::uint8_t* scan_result = nullptr;
    const std::uint8_t* scan_data = reinterpret_cast<const std::uint8_t*>(signature.c_str());

    for (auto current = scan_begin; current < scan_end; ++current) {
        if (*scan_data == '\?' || *current == GET_BYTE(scan_data)) {
            if (!scan_result)
                scan_result = current;

            if (!scan_data[2])
                return reinterpret_cast<std::uintptr_t>(scan_result);

            scan_data += (*(std::uint16_t*)scan_data == '\?\?' || *scan_data != '\?') ? 3 : 2;

            if (!*scan_data)
                return reinterpret_cast<std::uintptr_t>(scan_result);
        }
        else if (scan_result) {
            current = scan_result;
            scan_data = reinterpret_cast<const std::uint8_t*>(signature.c_str());
            scan_result = nullptr;
        }
    }

    return 0u;
}
