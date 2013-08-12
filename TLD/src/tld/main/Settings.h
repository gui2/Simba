#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

using std::string;

extern "C" {
#include <ccv.h>
}

class Settings
{
public:

    Settings();
    ~Settings();

    //Settings comments from libccv documentation for tld

    /* short-term lucas-kanade tracking parameters */
    int win_size_width; //these are the parts of the ccv_size_t struct that we need user to input
    int win_size_height;
    int level;
    float min_eigen;
    float min_forward_backward_error;
    /* image pyramid (different resolution) generation parameters */
    int interval;
    float shift;
    /* samples generation parameters */
    int min_win;
    float include_overlap;
    float exclude_overlap;
    /* fern classifier setting */
    int structs;
    int features;
    /* nearest neighbor thresholds */
    float validate_set; // 0.5 for conservative confidence
    float nnc_same; // the same object
    float nnc_thres; // highly correlated
    float nnc_verify; // correlated with tracking
    float nnc_beyond; // this is the cap of nnc_thres
    float nnc_collect; // modest correlated, worth to collect as negative example
    int bad_patches; // number of bad patches
    /* deformation round */
    int new_deform;
    int track_deform;
    float new_deform_angle;
    float track_deform_angle;
    float new_deform_scale;
    float track_deform_scale;
    float new_deform_shift;
    float track_deform_shift;
    /* top detections */
    int top_n;
    /* speed up technique, instead of running slide window at
     * every frame, we will rotate them, for example, slide window 1
     * only gets examined at frame % rotation == 1 */
    int rotation;

    std::string m_trackImagesPath;
    std::string m_analysisImagesPath;
    std::string m_resultsDirectory;
    std::string m_saveAnalysisDirectory;

    bool m_track;
    bool m_saveResults;
    bool m_analyze;
    bool m_saveAnalysis;

};


#endif /* SETTINGS_H */
