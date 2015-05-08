int tree_predict(double *attr) {
  if(attr[13] > 4.5) {
    if(attr[12] > 0.5) {
      if(attr[5] > 151.5) {
        if(attr[4] > 109) {
          if(attr[8] > 107) {
            return 1;
          } else {
            if(attr[1] > 63) {
              return -1;
            } else {
              return 1;
            }
          }
        } else {
          if(attr[1] > 55) {
            return 1;
          } else {
            return -1;
          }
        }
      } else {
        return -1;
      }
    } else {
      if(attr[3] > 3.5) {
        if(attr[1] > 56.5) {
          if(attr[8] > 125.5) {
            if(attr[4] > 165) {
              return 1;
            } else {
              return -1;
            }
          } else {
            return 1;
          }
        } else {
          if(attr[10] > 0.25) {
            return 1;
          } else {
            if(attr[1] > 42) {
              return -1;
            } else {
              return 1;
            }
          }
        }
      } else {
        if(attr[1] > 39) {
          if(attr[8] > 143) {
            return -1;
          } else {
            if(attr[1] > 60.5) {
              return -1;
            } else {
              return 1;
            }
          }
        } else {
          return 1;
        }
      }
    }
  } else {
    if(attr[3] > 3.5) {
      if(attr[12] > 0.5) {
        if(attr[2] > 0.5) {
          return 1;
        } else {
          if(attr[1] > 63.5) {
            return -1;
          } else {
            if(attr[1] > 59.5) {
              return 1;
            } else {
              return -1;
            }
          }
        }
      } else {
        if(attr[4] > 145) {
          if(attr[1] > 63) {
            return -1;
          } else {
            return 1;
          }
        } else {
          if(attr[8] > 96.5) {
            if(attr[5] > 316.5) {
              if(attr[5] > 342) {
                return -1;
              } else {
                return 1;
              }
            } else {
              return -1;
            }
          } else {
            return 1;
          }
        }
      }
    } else {
      if(attr[10] > 2.3) {
        if(attr[1] > 63.5) {
          return -1;
        } else {
          return 1;
        }
      } else {
        if(attr[5] > 154.5) {
          if(attr[5] > 272) {
            if(attr[3] > 1.5) {
              if(attr[12] > 1.5) {
                return 1;
              } else {
                return -1;
              }
            } else {
              return 1;
            }
          } else {
            if(attr[4] > 109) {
              return -1;
            } else {
              if(attr[2] > 0.5) {
                if(attr[1] > 49) {
                  return -1;
                } else {
                  return 1;
                }
              } else {
                return -1;
              }
            }
          }
        } else {
          if(attr[1] > 46.5) {
            return 1;
          } else {
            return -1;
          }
        }
      }
    }
  }
}
