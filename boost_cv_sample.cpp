#include <boost/python.hpp>
#include "cv2.hpp"

PyObject* GenImage(int width, int height) {
    cv::Mat cv_img(width, height, CV_32F, cv::Scalar(0.0));
    return pyopencv_from(cv_img);
}

PyObject* GenRects(int n) {
    vector_Rect2d rects;
    for (int i = 0; i < n; i++) {
        rects.push_back(cv::Rect2d(0, 1, 2, 3));
    }
    return pyopencv_from(rects);
}

PyObject* FillOne(PyObject* o) {
    cv::Mat cv_img;
    pyopencv_to(o, cv_img);
    cv_img.setTo(cv::Scalar(1));
    return pyopencv_from(cv_img);
}

BOOST_PYTHON_MODULE(libboost_cv_sample) {
    import_array();
    boost::python::def("gen_image", &GenImage);
    boost::python::def("gen_rects", &GenRects);
    boost::python::def("fill_one", &FillOne);
}
