/*
 * Name: Yash Khadgi
 * PRN: 24070521137
 * Batch: B2
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 50

void sender(int frames[], int size, int window_size);
void receiver(int frames[], int start, int window_size, int size);

int main() {
    int n, window_size;
    int frames[MAX_FRAMES];

    printf("Sliding Window Protocol Simulation (Go-Back-N)\n");
    printf("Enter number of frames to send (max %d): ", MAX_FRAMES);
    if (scanf("%d", &n) != 1 || n > MAX_FRAMES || n <= 0) {
        printf("Invalid number of frames.\n");
        return 0;
    }

    printf("Enter window size: ");
    if (scanf("%d", &window_size) != 1 || window_size <= 0 || window_size > n) {
        printf("Invalid window size.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        frames[i] = i;
    }

    sender(frames, n, window_size);

    return 0;
}

void sender(int frames[], int size, int window_size) {
    int base = 0;
    char choice;

    while (base < size) {
        printf("\nSender window: ");
        for (int i = base; i < base + window_size && i < size; i++) {
            printf("[%d] ", frames[i]);
        }
        printf("\nSending frames...\n");
        for (int i = base; i < base + window_size && i < size; i++) {
            printf("Sent frame: %d\n", frames[i]);
        }

        printf("\nSimulating receiver...\n");
        receiver(frames, base, window_size, size);

        printf("\nDid all frames receive correctly? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            base += window_size;
        } else {
            printf("Resending from frame %d...\n", frames[base]);
        }
    }

    printf("\nAll frames sent successfully!\n");
}

void receiver(int frames[], int start, int window_size, int size) {
    for (int i = start; i < start + window_size && i < size; i++) {
        printf("Received frame: %d, sending ACK: %d\n", frames[i], frames[i] + 1);
    }
}























































/*
================================================================================
                    LAB PRACTICAL EXAMINATION WRITE-UP (5 MARKS)
================================================================================
# **Go-Back-N (GBN) Sliding Window Protocol**

### **1. AIM**

To simulate the Go-Back-N (GBN) Sliding Window Protocol in C, demonstrating frame transmission, acknowledgment, window sliding and retransmission.

### **2. THEORY**

The Go-Back-N (GBN) Sliding Window Protocol is a flow control and error control technique used in computer networks. It allows the sender to transmit multiple frames before receiving acknowledgments, improving transmission efficiency through pipelining.

In this protocol, the sender can transmit multiple frames according to its window size, while the receiver accepts only one frame at a time in sequential order. The receiver sends acknowledgments (ACK) for successfully received frames.

If a frame is lost or damaged, the receiver discards that frame and subsequent out-of-order frames. The sender then retransmits the lost frame and all following frames in the current window. This process continues until all frames are successfully acknowledged.

### **3. ALGORITHM**

1. Start and input the total number of frames (`n`) and window size (`w`).
2. Initialize `base = 0`.
3. Send frames from `base` to `base + w - 1`, or until all frames are sent.
4. Display received frames and their acknowledgments (ACK).
5. Ask the user whether all frames were received correctly.
6. If Yes (`Y`), slide the window forward by updating `base = base + w`.
7. If No (`N`), retransmit all frames in the current window without changing `base`.
8. Repeat until all frames are acknowledged.
9. Stop.

### **4. CONCLUSION**

Successfully implemented the Go-Back-N Sliding Window Protocol in C. Demonstrated multiple frame transmission, acknowledgment, window sliding and retransmission when an error occurs.

    */
