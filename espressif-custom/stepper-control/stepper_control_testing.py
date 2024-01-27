from math import floor
import json

file = open("stepper_output.json", 'w')

stepper_driver_conversion = {}

STEP_RESOLUTION = 0.9

DEGREE_0 = 90
DEGREE_1 = 91
DEGREE_2 = 92

def round_to_stepper_res(angle: float) -> float:
    rounded = floor(angle / STEP_RESOLUTION) * STEP_RESOLUTION
    return rounded

def steps_req(angle):
    return angle / 1.8

print("---------------------------")
for i in range(0, 91, 1):
    result = round_to_stepper_res(i)
    stepper_driver_conversion["[" + str(i) + "] Computed Stepper Degree"] = result
    stepper_driver_conversion["[" + str(i) + "] Steps Required"] = steps_req(result)
    # print(f"[{i}] Steps Required: {steps_req(result)}")
print("---------------------------")

json.dump(stepper_driver_conversion, file)
