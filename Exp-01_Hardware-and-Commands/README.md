<!--
Name: Yash Khadgi
PRN: 24070521137
Batch: B2
-->

# Experiment 1: Basic Hardware Components & Networking Commands

## Hardware Components
* **NIC (Network Interface Card):** Hardware component enabling device connectivity to a network.
* **Switch:** Layer 2 device connecting devices within a LAN using MAC addresses.
* **Router:** Layer 3 device connecting multiple distinct networks using IP addresses.
* **UTP Cable (CAT6):** Media containing 4 twisted pairs of copper wire to reduce crosstalk.

## Essential CLI Commands
* `ping <host>`: Tests end-to-end IP reachability and round-trip time.
* `tracert <host>` / `traceroute <host>`: Displays route hops to a remote destination.
* `ipconfig` / `ifconfig`: Displays local interface IP, subnet mask, and default gateway.
* `netstat -an`: Lists all active socket connections and listening ports.
* `nslookup <domain>`: Queries DNS servers for IP address mapping.
* `arp -a`: Displays local ARP cache mapping IP addresses to MAC addresses.























































<!--
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================
-->

# Practical Examination Write-Up: Experiment 1

### 1. AIM
To study and identify fundamental computer networking hardware components (NIC, Switch, Router, UTP CAT6 Cable) and demonstrate network diagnosis and configuration using essential CLI commands (`ping`, `tracert`, `ipconfig`, `netstat`, `nslookup`, `arp`).

### 2. THEORY
* **Layer 1 (Physical Layer):**
  - **NIC (Network Interface Card):** Connects host to physical transmission medium; holds a unique, burnt-in 48-bit MAC address.
  - **UTP CAT6 Cable:** 4 twisted copper pairs to eliminate crosstalk and electromagnetic interference (EMI); supports up to 10 Gbps over 55m.
* **Layer 2 (Data Link Layer):**
  - **Switch:** Multiport intelligent bridge; inspects incoming Ethernet frame headers, builds dynamic MAC address tables, and forwards frames only to the designated destination port (unicast), eliminating collisions.
* **Layer 3 (Network Layer):**
  - **Router:** Interconnects logically disparate IP networks; maintains routing tables, executes routing algorithms, and determines the optimal path across autonomous systems.
* **Diagnostic Protocols & Command Theory:**
  - `ping`: Employs **ICMP (Internet Control Message Protocol)** Echo Request (Type 8) and Echo Reply (Type 0) packets to verify end-to-end IP reachability, packet loss, and round-trip time (RTT).
  - `tracert` / `traceroute`: Exploits the **Time-To-Live (TTL)** field in IP headers. Generates packets starting at TTL=1, incrementing by 1 per probe. When TTL expires, intermediate routers return ICMP Time Exceeded (Type 11), mapping every hop along the route.
  - `ipconfig` / `ifconfig`: Displays host network interface parameters: IPv4/IPv6 address, Subnet Mask, Default Gateway, and DHCP/DNS lease details.
  - `arp -a`: Queries and displays the **Address Resolution Protocol (ARP)** cache mapping 32-bit IPv4 addresses to 48-bit physical MAC addresses.
  - `netstat -an`: Inspects active TCP/UDP sockets, open listening ports, and connection states (`LISTENING`, `ESTABLISHED`, `TIME_WAIT`).
  - `nslookup`: Queries DNS servers over UDP/TCP port 53 to resolve Fully Qualified Domain Names (FQDN) to IP addresses and verify Resource Records (`A`, `AAAA`, `NS`, `MX`).

### 3. EXPLANATION / PROCEDURE
1. **Hardware Inspection:** Examine physical lab infrastructure—identify NIC cards in workstations, RJ45 patch cables, 24/48-port rack-mounted switches, and gateway routers.
2. **Local TCP/IP Stack Check:** Execute `ping 127.0.0.1` (loopback IP) to confirm TCP/IP protocol stack initialization on the OS.
3. **Host IP Configuration:** Execute `ipconfig /all` to retrieve assigned IP address, Subnet Mask, Gateway IP, and physical MAC address.
4. **End-to-End Connectivity:** Execute `ping 8.8.8.8` to test public internet routing and calculate latency.
5. **Path Tracing:** Run `tracert google.com` to observe hop-by-hop packet routing and identify latency bottlenecks at intermediate gateways.
6. **Socket Inspection:** Execute `netstat -ano` to list active TCP sockets and identify background daemon processes binding to specific port numbers.
7. **Address Resolution Cache:** Run `arp -a` to view dynamic IP-to-MAC resolutions obtained on the local subnet.

### 4. CONCLUSION
Successfully inspected and identified core networking hardware devices and demonstrated the operation of essential network diagnostic commands. Evaluated round-trip time, route hops, socket states, and local ARP/DNS resolution tables.
-->
