import csv
import sys
from collections import Counter

def analyze_log(filename):
    print(f"Reading telemetry file: {filename}...\n")
    
    total_readings = 0
    values = []
    statuses = Counter()
    
    try:
        with open(filename, mode='r') as file:
            reader = csv.DictReader(file)
            
            for row in reader:
                total_readings += 1
                val = int(row['SimulatedValue'])
                values.append(val)
                statuses[row['Status']] += 1
                
        if total_readings == 0:
            print("The log file is empty.")
            return

        avg_value = sum(values) / total_readings
        min_value = min(values)
        max_value = max(values)
        
        print("=== TELEMETRY ANALYSIS REPORT ===")
        print(f"Total Readings Processed : {total_readings}")
        print(f"Average Sensor Value     : {avg_value:.2f}")
        print(f"Minimum Sensor Value     : {min_value}")
        print(f"Maximum Sensor Value     : {max_value}")
        print("---------------------------------")
        print("Status Breakdown:")
        for status, count in statuses.items():
            print(f"  - {status}: {count}")
        print("=================================")

    except FileNotFoundError:
        print(f"Error: Could not find file '{filename}'. Run your C logger first!")

if __name__ == "__main__":
    target_file = sys.argv[1] if len(sys.argv) > 1 else "sensor_log.csv"
    analyze_log(target_file)