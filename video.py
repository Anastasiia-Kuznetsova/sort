import os
import cv2
from PIL import Image
def generate_video(filename, filedir, name):
    image_folder = '.'
    video_name = filename
    os.chdir(filedir)

    images = [img for img in sorted(os.listdir(image_folder))]
    frame = cv2.imread(os.path.join(image_folder, images[0]))

    height, width, layers = frame.shape

    video = cv2.VideoWriter(video_name, 0, 60, (width, height))

    for image in images:
        video.write(cv2.imread(os.path.join(image_folder, image)))
    video.release()

    cap = cv2.VideoCapture(filename)
    # Check if camera opened successfully



    # Read until video is completed
    while (cap.isOpened()):
        # Capture frame-by-frame
        ret, frame = cap.read()
        if ret == True:
            frame = cv2.resize(frame, (1000, 1000),
                               interpolation=cv2.INTER_AREA)
            cv2.imshow(name, frame)
            if cv2.waitKey(25) & 0xFF == ord('q'):
                break
        else:
            if cv2.waitKey(25) & 0xFF == ord('q'):
                break
    cap.release()
    cv2.destroyAllWindows()


with open('whatsort.txt') as file:
    f = file.readline()
if int(f) == 1:
    generate_video('/home/anastasia/sorts/bubble.avi', "/home/anastasia/sorts/bubble", "bubble sort")
elif int(f) == 2:
    generate_video('/home/anastasia/sorts/insert.avi', "/home/anastasia/sorts/insert", "insertion sort")
elif int(f) == 3:
    generate_video('/home/anastasia/sorts/choice.avi', "/home/anastasia/sorts/choice", "choice sort")
elif int(f) == 4:
    generate_video('/home/anastasia/sorts/heap.avi', "/home/anastasia/sorts/heap", "heap sort")