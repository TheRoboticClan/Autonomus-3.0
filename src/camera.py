import cv2
import serial
import time

# Open serial port to Arduino (adjust if needed)
arduino = serial.Serial('/dev/ttyUSB0', 9600)
time.sleep(2)  # Give Arduino time to reset

# Open the default camera (usually rear)
cap = cv2.VideoCapture(0)

# Define HSV color ranges
green_lower = (40, 40, 40)
green_upper = (80, 255, 255)

red_lower1 = (0, 120, 70)
red_upper1 = (10, 255, 255)
red_lower2 = (160, 120, 70)
red_upper2 = (180, 255, 255)

def detect_color(frame):
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    green_mask = cv2.inRange(hsv, green_lower, green_upper)
    red_mask1 = cv2.inRange(hsv, red_lower1, red_upper1)
    red_mask2 = cv2.inRange(hsv, red_lower2, red_upper2)
    red_mask = red_mask1 | red_mask2

    green_pixels = cv2.countNonZero(green_mask)
    red_pixels = cv2.countNonZero(red_mask)

    if green_pixels > red_pixels and green_pixels > 500:
        return "GREEN"
    elif red_pixels > green_pixels and red_pixels > 500:
        return "RED"
    else:
        return None

while True:
    ret, frame = cap.read()
    if not ret:
        break

    color = detect_color(frame)
    if color:
        print(f"Detected: {color}")
        arduino.write((color + '\n').encode())  # Send to Arduino
        time.sleep(2)  # Optional delay to avoid spamming

    # Optional preview (can be removed for performance)
    # cv2.imshow("Camera", frame)
    # if cv2.waitKey(1) == 27:  # Press ESC to exit
    #     break

# Cleanup
cap.release()
# cv2.destroyAllWindows()
arduino.close()
