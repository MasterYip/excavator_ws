import cv2
import numpy as np
import sys


def find_bgr(event,x,y,flags,param):
    if event ==cv2.EVENT_LBUTTONDBLCLK:
        hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
  #      print("bgr="+str(img[y][x]))
        print("hsv="+str(hsv[y][x]))

def nothing(x):
    pass

if __name__ == "__main__":
    cap=cv2.VideoCapture(0)
    ret,frame=cap.read()
    if not ret:
        cap.open(0)

    while(ret):
        ret,frame=cap.read()
        cv2.imshow('camera',frame)
        k=cv2.waitKey(1)
        if k==ord('p'):
            img=frame
            break
        if k==27:
            cap.release()
            cv2.destroyAllWindows()
            sys.exit()
            break
    cap.release()
    cv2.destroyAllWindows()

    cv2.imshow('image',img)
    cv2.setMouseCallback('image',find_bgr)
    
    cv2.namedWindow("HSV_Bar",cv2.WINDOW_NORMAL)
    cv2.createTrackbar('H_min','HSV_Bar',0,179,nothing)
    cv2.createTrackbar('H_max','HSV_Bar',0,179,nothing)
    cv2.createTrackbar('S_min','HSV_Bar',0,255,nothing)
    cv2.createTrackbar('S_max','HSV_Bar',0,255,nothing)
    cv2.createTrackbar('V_min','HSV_Bar',0,255,nothing)
    cv2.createTrackbar('V_max','HSV_Bar',0,255,nothing)

    #cv2.createTrackbar('Mask_ON/OFF','HSV_Bar',0,1,nothing)

    while True:
    #     Flag=cv2.getTrackbarPos('ON/OFF','HSV_Bar')
    #     if not Flag:
        cv2.imshow('image',img)
        h1=cv2.getTrackbarPos('H_min','HSV_Bar')
        h2=cv2.getTrackbarPos('H_max','HSV_Bar')
        s1=cv2.getTrackbarPos('S_min','HSV_Bar')
        s2=cv2.getTrackbarPos('S_max','HSV_Bar')
        v1=cv2.getTrackbarPos('V_min','HSV_Bar')
        v2=cv2.getTrackbarPos('V_max','HSV_Bar')
        low_range=np.array([h1,s1,v1],dtype=np.uint8)
        up_range=np.array([h2,s2,v2],dtype=np.uint8)
        hsv=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
        mask=cv2.inRange(hsv,low_range,up_range)
        cv2.imshow('Mask',mask)

        if cv2.waitKey(1)==ord('s'):
            with open('./thresholds_hsv.txt', 'a') as f:
                thre_name=input("the item's name:")
                f.write(thre_name+':  ')
                f.write('low_range: (%d,%d,%d)'%(low_range[0],low_range[1],low_range[2]))
                f.write('up_range:  (%d,%d,%d)\n'%(up_range[0],up_range[1],up_range[2]))
                f.close()
                break
                
            
        if cv2.waitKey(1)==27:
            break

    cv2.destroyAllWindows() 