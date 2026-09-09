# Real-Time Telemetry & Data Acquisition (DAQ) Pipeline

---


A high-performance, cross-platform systems engineering project demonstrating a low-level data acquisition daemon written in **C**, paired with an automated telemetry analytics pipeline written in **Python**.

Designed to showcase low-level resource management, real-time signal handling, dynamic runtime configuration, and inter-process observability.

---

## Core Components

- **C Data Acquisition Daemon (`c_src/main.c`)**: 
  - Polls system metrics via the Win32 API.
  - Features configurable polling intervals (`argc`/`argv`), immediate buffer flushing (`fflush`), and graceful shutdown intercepts (`SIGINT` / `Ctrl+C`).
- **Python Telemetry Pipeline (`python_src/analyzer.py`)**: 
  - Consumes generated CSV logs in real time.
  - Computes aggregated statistical reports, latency breakdowns, and status alerts.

---

## Getting Started

1. **Build the C Daemon**:
   ```bash
   gcc c_src/main.c -o sensor_logger.exe