#include "GerstnerWaveModel.h"

GerstnerWaveModel::GerstnerWaveModel(double *d, double ali, double i, double aju) : WaveModel(d, ali, i, aju){
}

GerstnerWaveModel::GerstnerWaveModel(const GerstnerWaveModel &w) : WaveModel(w) {
}
