import sys
sys.path.append('../build/lib')

import libboost_cv_sample

if __name__ == '__main__':
    img = libboost_cv_sample.gen_image(10, 10)
    img = libboost_cv_sample.fill_one(img)
    print(img)
