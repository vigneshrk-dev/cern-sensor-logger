# Real-Time Telemetry & Data Acquisition (DAQ) Pipeline

A high-performance, cross-platform systems engineering project demonstrating a low-level data acquisition daemon written in **C**, paired with an automated telemetry analytics pipeline written in **Python**. 

Designed to showcase low-level resource management, real-time signal handling, dynamic runtime configuration, and inter-process observability.

---

## System Architecture & Workflow

```text
 [ C Daemon (Sensor Stream) ] 
       │
       ├── Configurable Polling Interval (argc/argv)
       ├── Immediate Buffer Flushing (fflush)
       └── Graceful Shutdown Intercept (SIGINT / Ctrl+C)
       │
       ▼
  sensor_log.csv ────────► [ Python Analytics Consumer ] ──► Aggregated Statistical Report & Status Breakdown

 <img width="1812" height="975" alt="Screenshot 2026-09-08 152009" src="https://github.com/user-attachments/assets/ac81ac4c-9e42-48e5-83d6-786a5830526b" />
 <img width="1752" height="927" alt="Screenshot 2026-09-08 152108" src="https://github.com/user-attachments/assets/6b79852e-f5d6-4b6e-acc9-7ccc8dd33f34" />
  
