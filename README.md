<p align="center">
<h1 align="center">csgo-server-lagger</h1>
<p align="center">
  <img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="appveyor-ci" />
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="appveyor-ci" />
  <img src="https://img.shields.io/badge/Counter_Strike-000000?style=for-the-badge&logo=counter-strike&logoColor=white" alt="appveyor-ci" />
</p>
<p align="center">
  <strong>csgo-server-lagger</strong> is a standalone executable integrating <strong>winsocket</strong> functions in order to <strong>overload</strong> cs:go community servers. <br><br>By sending a <strong>0x1000</strong> bytes large buffer filled with null bytes <strong>(0x00)</strong> we can cause a lag. <br>If the server is not designed to handle such a high rate of incoming requests, it may become overloaded. This could lead to performance degradation or even server crashes, especially if the server lacks sufficient resources to process incoming requests at that rate.</br>Sending data at such a high frequency <strong>(15 milliseconds)</strong> can lead to a significant increase in network traffic, potentially saturating the network connection between your client and the server. <br>This could impact other network activities and cause congestion (var and sv jumps).</br> <br>Processing incoming data consumes CPU and memory resources on the server.</br> If the server receives data at a rapid rate, it may struggle to allocate enough resources to process each request, resulting in resource exhaustion. <br>The server <strong>may</strong> want to establish and maintain a connection for each incoming request.</br> Opening and closing connections frequently can potentially exhaust the server's ability to handle new connections. <br>The impact also depends on the server's application logic.</br> <br>Some servers may simply ignore or discard incoming empty requests, while others may process them in some way.</br> If the server is not adequately protected, a sustained attack like this could be part of a larger distributed denial of service <strong>DDoS</strong> attack, effectively making the server inaccessible to legitimate users.

</p>
</p>
</p>

</br></br>


## Usage

```cpp
~ home / csgo-server-lagger / bin ~ .\csgo-server-lagger.exe
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[GPLv3](https://choosealicense.com/licenses/gpl-3.0/)

## 💵 Want to buy me a Coffee?
<p align="left">
  <img src="https://img.shields.io/badge/Bitcoin-000000?style=for-the-badge&logo=bitcoin&logoColor=white" alt="appveyor-ci" />
  <img src="https://img.shields.io/badge/Ethereum-3C3C3D?style=for-the-badge&logo=Ethereum&logoColor=white" alt="appveyor-ci" />
  <img src="https://img.shields.io/badge/Litecoin-A6A9AA?style=for-the-badge&logo=Litecoin&logoColor=white" alt="appveyor-ci" />
</p>

     - Donate BTC at `bc1q07aq4n66mz3f3z56lm72sug6rvfm6qp3cydcs7`
     - Donate ETH at `0x4c9e8710b931f580B5d776c7989CE6e323ed1b34`
     - Donate LTC at `LgtxE9ybYhtm7NTrMBjUNQYoJs9tGGrEyC`
