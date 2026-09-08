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
  
  
