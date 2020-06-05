import rosbag
import rospy
import time

sec_time = 0.0
nsec_time = 0
sec_iter = 5
counter = 0
find_time_iter_flag = 0;
max_nsce = 2147483647/2 
nsec_iter = max_nsce / sec_iter

with rosbag.Bag('merged_bag_newtime.bag', 'w') as outbag:
    for topic, msg, t in rosbag.Bag('merged_bag2.bag').read_messages():
        # This also replaces tf timestamps under the assumption 
        # that all transforms in the message share the same timestamp
        
        if counter < sec_iter - 1:
            nsec_time = nsec_time + nsec_iter 
            counter = counter + 1 
        else:
            sec_time = sec_time + 1
            nsec_time = 1
            counter = 0

        msg.header.stamp.secs = sec_time
        msg.header.stamp.nsecs = nsec_time
            
	print("header is ", msg.header)

        if topic == "horizontal_laser_2d" and msg.header:
                outbag.write(topic, msg, msg.header.stamp)
        else:
		print("wrong topic")
		break
