
#include <stdio.h>

int main() {
    int capacity, rate, n, tokens = 0, packet;

    printf("Enter bucket capacity: ");
    scanf("%d", &capacity);

    printf("Enter token generation rate: ");
    scanf("%d", &rate);

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("\nEnter packet %d size: ", i);
        scanf("%d", &packet);

        tokens += rate;

        if (tokens > capacity)
            tokens = capacity;

        printf("Available tokens: %d\n", tokens);

        if (packet <= tokens) {
            tokens -= packet;
            printf("Packet transmitted successfully!\n");
        } else {
            printf("Insufficient tokens! Packet dropped.\n");
        }
    }

    return 0;
}























































/*


# **Token Bucket Algorithm in C**

### **1. AIM**

To implement the Token Bucket Algorithm in C for network traffic shaping and congestion control.

### **2. THEORY**

The Token Bucket Algorithm is a traffic control technique used in computer networks to regulate the rate of data transmission. Tokens are added to a bucket at a fixed rate, and each packet requires tokens before it can be transmitted.

The bucket has a fixed capacity. If the bucket becomes full, newly generated tokens are discarded. If sufficient tokens are available, packets are transmitted; otherwise, they are delayed or dropped. This algorithm controls the average transmission rate while allowing short bursts of data.

### **3. ALGORITHM**

1. **Start** and initialize the number of available tokens as `tokens = 0`.
2. **Input** the bucket capacity, token generation rate and total number of packets.
3. For each packet:
   - Input the packet size.
   - Add newly generated tokens:

\\[ tokens = tokens + rate \\]

\- If tokens exceed bucket capacity, limit them to the maximum capacity:

\\[ tokens = \min(tokens, capacity) \\]

4\. **Check packet transmission:**

\- If `packet <= tokens`:

- Transmit the packet.
- Reduce tokens by packet size:

\\[ tokens = tokens - packet \\]

\- Otherwise, drop the packet due to insufficient tokens.

5. Repeat Steps 3–4 until all packets are processed.
6. **Stop.**

### **4. CONCLUSION**

*/
