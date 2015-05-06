int tree_predict(double *attr) {
  if(attr[2] > 0.5) {
    if(attr[6] > 0.5) {
      if(attr[9] > 0.5) {
        return 1;
      } else {
        if(attr[10] > 0.5) {
          if(attr[12] > 0.5) {
            return 1;
          } else {
            return -1;
          }
        } else {
          if(attr[12] > 0.5) {
            if(attr[11] > 1.5) {
              if(attr[12] > 1.5) {
                return 1;
              } else {
                return -1;
              }
            } else {
              return -1;
            }
          } else {
            return -1;
          }
        }
      }
    } else {
      if(attr[9] > 0.5) {
        if(attr[10] > 0.5) {
          if(attr[12] > 0.5) {
            if(attr[3] > 2) {
              return 1;
            } else {
              return -1;
            }
          } else {
            if(attr[11] > 2.5) {
              return 1;
            } else {
              if(attr[10] > 1.5) {
                if(attr[10] > 2.5) {
                  if(attr[1] > 41.5) {
                    return -1;
                  } else {
                    return 1;
                  }
                } else {
                  return 1;
                }
              } else {
                if(attr[5] > 198.5) {
                  if(attr[8] > 125.5) {
                    return -1;
                  } else {
                    return 1;
                  }
                } else {
                  return 1;
                }
              }
            }
          }
        } else {
          if(attr[12] > 0.5) {
            if(attr[8] > 106.5) {
              return 1;
            } else {
              return -1;
            }
          } else {
            if(attr[11] > 1.5) {
              return 1;
            } else {
              if(attr[3] > 2.5) {
                if(attr[3] > 3.5) {
                  if(attr[1] > 43) {
                    if(attr[4] > 146) {
                      return 1;
                    } else {
                      return -1;
                    }
                  } else {
                    return 1;
                  }
                } else {
                  return -1;
                }
              } else {
                return -1;
              }
            }
          }
        }
      } else {
        if(attr[10] > 0.5) {
          if(attr[12] > 0.5) {
            if(attr[1] > 46) {
              return 1;
            } else {
              return -1;
            }
          } else {
            if(attr[11] > 2.5) {
              return -1;
            } else {
              if(attr[10] > 1.5) {
                if(attr[10] > 2.5) {
                  return 1;
                } else {
                  if(attr[3] > 3.5) {
                    if(attr[11] > 1.5) {
                      return 1;
                    } else {
                      return -1;
                    }
                  } else {
                    return -1;
                  }
                }
              } else {
                if(attr[1] > 61.5) {
                  return 1;
                } else {
                  return -1;
                }
              }
            }
          }
        } else {
          if(attr[12] > 0.5) {
            if(attr[12] > 1.5) {
              if(attr[12] > 2.5) {
                return 1;
              } else {
                return -1;
              }
            } else {
              if(attr[11] > 1.5) {
                if(attr[11] > 2.5) {
                  return -1;
                } else {
                  return 1;
                }
              } else {
                if(attr[1] > 48) {
                  if(attr[5] > 215.5) {
                    return 1;
                  } else {
                    return -1;
                  }
                } else {
                  return 1;
                }
              }
            }
          } else {
            if(attr[11] > 1.5) {
              if(attr[1] > 62.5) {
                return -1;
              } else {
                if(attr[4] > 127) {
                  return -1;
                } else {
                  return 1;
                }
              }
            } else {
              if(attr[3] > 1.5) {
                if(attr[1] > 40.5) {
                  if(attr[5] > 174.5) {
                    if(attr[8] > 140.5) {
                      if(attr[8] > 142) {
                        if(attr[1] > 64.5) {
                          return -1;
                        } else {
                          if(attr[8] > 143.5) {
                            if(attr[8] > 147) {
                              if(attr[8] > 152.5) {
                                return -1;
                              } else {
                                if(attr[1] > 44.5) {
                                  return 1;
                                } else {
                                  return -1;
                                }
                              }
                            } else {
                              return 1;
                            }
                          } else {
                            return -1;
                          }
                        }
                      } else {
                        return 1;
                      }
                    } else {
                      return -1;
                    }
                  } else {
                    return 1;
                  }
                } else {
                  return 1;
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
    }
  } else {
    if(attr[6] > 0.5) {
      if(attr[9] > 0.5) {
        if(attr[10] > 0.5) {
          return 1;
        } else {
          return -1;
        }
      } else {
        if(attr[10] > 0.5) {
          return 1;
        } else {
          if(attr[12] > 0.5) {
            if(attr[12] > 1.5) {
              return 1;
            } else {
              return -1;
            }
          } else {
            return -1;
          }
        }
      }
    } else {
      if(attr[7] > 0.5) {
        if(attr[9] > 0.5) {
          if(attr[10] > 0.5) {
            if(attr[11] > 2.5) {
              return -1;
            } else {
              return 1;
            }
          } else {
            return -1;
          }
        } else {
          if(attr[10] > 0.5) {
            if(attr[10] > 1.5) {
              return 1;
            } else {
              if(attr[8] > 114.5) {
                return -1;
              } else {
                return 1;
              }
            }
          } else {
            if(attr[12] > 0.5) {
              return -1;
            } else {
              if(attr[11] > 1.5) {
                return -1;
              } else {
                if(attr[3] > 3.5) {
                  if(attr[1] > 60.5) {
                    return 1;
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
              }
            }
          }
        }
      } else {
        if(attr[9] > 0.5) {
          if(attr[10] > 0.5) {
            return 1;
          } else {
            if(attr[11] > 1.5) {
              return 1;
            } else {
              return -1;
            }
          }
        } else {
          return -1;
        }
      }
    }
  }
}
