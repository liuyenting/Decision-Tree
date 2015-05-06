int tree_predict(double *attr) {
  if(attr[2] > 0.5) {
    if(attr[6] > 0.5) {
      if(attr[9] > 0.5) {
        if(attr[10] > 0.5) {
          if(attr[12] > 0.5) {
            if(attr[11] > 1.5) {
              return 1;
            } else {
              return 1;
            }
          } else {
            if(attr[1] > 54.5) {
              return 1;
            } else {
              return 1;
            }
          }
        } else {
          if(attr[3] > 3.5) {
            return 1;
          } else {
            return 1;
          }
        }
      } else {
        if(attr[10] > 0.5) {
          if(attr[12] > 0.5) {
            if(attr[10] > 1.5) {
              return 1;
            } else {
              if(attr[1] > 61) {
                return 1;
              } else {
                return 1;
              }
            }
          } else {
            if(attr[10] > 1.5) {
              return -1;
            } else {
              return -1;
            }
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
              if(attr[3] > 3.5) {
                return -1;
              } else {
                if(attr[12] > 1.5) {
                  if(attr[12] > 2.5) {
                    return -1;
                  } else {
                    return -1;
                  }
                } else {
                  return -1;
                }
              }
            }
          } else {
            if(attr[3] > 2.5) {
              if(attr[1] > 50) {
                return -1;
              } else {
                return -1;
              }
            } else {
              if(attr[1] > 49) {
                if(attr[1] > 57) {
                  return -1;
                } else {
                  return -1;
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
          if(attr[12] > 0.5) {
            if(attr[3] > 2) {
              if(attr[1] > 46.5) {
                if(attr[3] > 3.5) {
                  if(attr[11] > 1.5) {
                    if(attr[11] > 2.5) {
                      return 1;
                    } else {
                      if(attr[1] > 49) {
                        if(attr[1] > 52) {
                          if(attr[1] > 53.5) {
                            if(attr[1] > 64.5) {
                              return 1;
                            } else {
                              if(attr[12] > 1.5) {
                                if(attr[1] > 56) {
                                  if(attr[1] > 60) {
                                    return 1;
                                  } else {
                                    return 1;
                                  }
                                } else {
                                  return 1;
                                }
                              } else {
                                if(attr[10] > 1.5) {
                                  if(attr[10] > 2.5) {
                                    if(attr[4] > 129) {
                                      return 1;
                                    } else {
                                      return 1;
                                    }
                                  } else {
                                    if(attr[13] > 6.5) {
                                      return 1;
                                    } else {
                                      return 1;
                                    }
                                  }
                                } else {
                                  if(attr[1] > 58) {
                                    return 1;
                                  } else {
                                    return 1;
                                  }
                                }
                              }
                            }
                          } else {
                            return 1;
                          }
                        } else {
                          return 1;
                        }
                      } else {
                        return 1;
                      }
                    }
                  } else {
                    return 1;
                  }
                } else {
                  return 1;
                }
              } else {
                return 1;
              }
            } else {
              return -1;
            }
          } else {
            if(attr[11] > 2.5) {
              if(attr[10] > 2.5) {
                if(attr[1] > 57) {
                  return 1;
                } else {
                  return 1;
                }
              } else {
                return 1;
              }
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
                    if(attr[11] > 1.5) {
                      if(attr[3] > 3.5) {
                        return -1;
                      } else {
                        if(attr[8] > 143.5) {
                          return -1;
                        } else {
                          return -1;
                        }
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
              }
            }
          }
        } else {
          if(attr[12] > 0.5) {
            if(attr[8] > 106.5) {
              if(attr[1] > 49.5) {
                if(attr[12] > 1.5) {
                  if(attr[1] > 66.5) {
                    if(attr[11] > 1.5) {
                      return 1;
                    } else {
                      return 1;
                    }
                  } else {
                    return 1;
                  }
                } else {
                  if(attr[11] > 1.5) {
                    if(attr[1] > 55.5) {
                      return 1;
                    } else {
                      return 1;
                    }
                  } else {
                    if(attr[1] > 62.5) {
                      return 1;
                    } else {
                      return 1;
                    }
                  }
                }
              } else {
                return 1;
              }
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
                      if(attr[1] > 52) {
                        if(attr[1] > 55) {
                          return -1;
                        } else {
                          return -1;
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
                return -1;
              }
            }
          }
        }
      } else {
        if(attr[10] > 0.5) {
          if(attr[12] > 0.5) {
            if(attr[1] > 46) {
              if(attr[3] > 1.5) {
                if(attr[3] > 2.5) {
                  if(attr[1] > 50.5) {
                    if(attr[1] > 55) {
                      if(attr[11] > 1.5) {
                        if(attr[3] > 3.5) {
                          if(attr[10] > 1.5) {
                            if(attr[12] > 1.5) {
                              if(attr[12] > 2.5) {
                                return 1;
                              } else {
                                return 1;
                              }
                            } else {
                              return 1;
                            }
                          } else {
                            if(attr[12] > 1.5) {
                              return 1;
                            } else {
                              return 1;
                            }
                          }
                        } else {
                          if(attr[1] > 63.5) {
                            return 1;
                          } else {
                            return 1;
                          }
                        }
                      } else {
                        return 1;
                      }
                    } else {
                      return 1;
                    }
                  } else {
                    return 1;
                  }
                } else {
                  return 1;
                }
              } else {
                return 1;
              }
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
                  if(attr[11] > 1.5) {
                    if(attr[1] > 49.5) {
                      return -1;
                    } else {
                      return -1;
                    }
                  } else {
                    if(attr[3] > 3.5) {
                      return -1;
                    } else {
                      return -1;
                    }
                  }
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
                  if(attr[1] > 53.5) {
                    return 1;
                  } else {
                    return 1;
                  }
                }
              } else {
                if(attr[1] > 48) {
                  if(attr[5] > 215.5) {
                    if(attr[1] > 53) {
                      if(attr[1] > 56) {
                        return 1;
                      } else {
                        return 1;
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
              }
            }
          } else {
            if(attr[11] > 1.5) {
              if(attr[1] > 62.5) {
                return -1;
              } else {
                if(attr[4] > 127) {
                  if(attr[1] > 53.5) {
                    return -1;
                  } else {
                    return -1;
                  }
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
                                if(attr[1] > 57.5) {
                                  return -1;
                                } else {
                                  if(attr[4] > 109) {
                                    if(attr[5] > 203.5) {
                                      if(attr[5] > 216.5) {
                                        if(attr[4] > 111) {
                                          if(attr[1] > 41.5) {
                                            if(attr[5] > 224) {
                                              if(attr[3] > 2.5) {
                                                if(attr[3] > 3.5) {
                                                  return -1;
                                                } else {
                                                  if(attr[4] > 130) {
                                                    return -1;
                                                  } else {
                                                    return -1;
                                                  }
                                                }
                                              } else {
                                                if(attr[1] > 43.5) {
                                                  if(attr[1] > 55.5) {
                                                    return -1;
                                                  } else {
                                                    if(attr[1] > 50) {
                                                      return -1;
                                                    } else {
                                                      return -1;
                                                    }
                                                  }
                                                } else {
                                                  return -1;
                                                }
                                              }
                                            } else {
                                              return -1;
                                            }
                                          } else {
                                            return -1;
                                          }
                                        } else {
                                          return -1;
                                        }
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
          if(attr[11] > 2.5) {
            return 1;
          } else {
            return 1;
          }
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
              if(attr[1] > 68) {
                return -1;
              } else {
                return -1;
              }
            }
          } else {
            if(attr[1] > 57) {
              return -1;
            } else {
              return -1;
            }
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
              if(attr[1] > 55.5) {
                return 1;
              } else {
                return 1;
              }
            }
          } else {
            if(attr[12] > 0.5) {
              return -1;
            } else {
              if(attr[3] > 3.5) {
                if(attr[1] > 45.5) {
                  return -1;
                } else {
                  return -1;
                }
              } else {
                return -1;
              }
            }
          }
        } else {
          if(attr[10] > 0.5) {
            if(attr[10] > 1.5) {
              if(attr[12] > 2.5) {
                return 1;
              } else {
                return 1;
              }
            } else {
              if(attr[8] > 114.5) {
                if(attr[3] > 2.5) {
                  if(attr[7] > 1.5) {
                    if(attr[3] > 3.5) {
                      if(attr[1] > 60) {
                        return -1;
                      } else {
                        return -1;
                      }
                    } else {
                      if(attr[1] > 67.5) {
                        return -1;
                      } else {
                        return -1;
                      }
                    }
                  } else {
                    return -1;
                  }
                } else {
                  return -1;
                }
              } else {
                return 1;
              }
            }
          } else {
            if(attr[12] > 0.5) {
              return -1;
            } else {
              if(attr[11] > 1.5) {
                if(attr[3] > 2.5) {
                  if(attr[3] > 3.5) {
                    return -1;
                  } else {
                    return -1;
                  }
                } else {
                  return -1;
                }
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
                  if(attr[1] > 59.5) {
                    return -1;
                  } else {
                    if(attr[1] > 52.5) {
                      return -1;
                    } else {
                      if(attr[4] > 125) {
                        return -1;
                      } else {
                        return -1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      } else {
        if(attr[9] > 0.5) {
          if(attr[10] > 0.5) {
            if(attr[1] > 62.5) {
              return 1;
            } else {
              if(attr[1] > 56.5) {
                return 1;
              } else {
                return 1;
              }
            }
          } else {
            if(attr[11] > 1.5) {
              return 1;
            } else {
              if(attr[1] > 60.5) {
                return -1;
              } else {
                return -1;
              }
            }
          }
        } else {
          if(attr[10] > 0.5) {
            if(attr[10] > 1.5) {
              if(attr[11] > 2.5) {
                return -1;
              } else {
                return -1;
              }
            } else {
              if(attr[3] > 1.5) {
                if(attr[3] > 2.5) {
                  if(attr[3] > 3.5) {
                    return -1;
                  } else {
                    if(attr[1] > 52) {
                      return -1;
                    } else {
                      return -1;
                    }
                  }
                } else {
                  return -1;
                }
              } else {
                return -1;
              }
            }
          } else {
            if(attr[12] > 0.5) {
              if(attr[11] > 1.5) {
                return -1;
              } else {
                if(attr[4] > 105.5) {
                  if(attr[3] > 2.5) {
                    if(attr[3] > 3.5) {
                      return -1;
                    } else {
                      if(attr[1] > 60.5) {
                        return -1;
                      } else {
                        return -1;
                      }
                    }
                  } else {
                    return -1;
                  }
                } else {
                  return -1;
                }
              }
            } else {
              if(attr[3] > 1.5) {
                if(attr[1] > 35.5) {
                  if(attr[1] > 38) {
                    if(attr[1] > 40) {
                      if(attr[1] > 41.5) {
                        if(attr[1] > 43) {
                          if(attr[1] > 44.5) {
                            if(attr[1] > 45.5) {
                              if(attr[11] > 1.5) {
                                return -1;
                              } else {
                                if(attr[3] > 2.5) {
                                  if(attr[1] > 48.5) {
                                    if(attr[3] > 3.5) {
                                      if(attr[1] > 55.5) {
                                        return -1;
                                      } else {
                                        return -1;
                                      }
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
                            } else {
                              return -1;
                            }
                          } else {
                            return -1;
                          }
                        } else {
                          return -1;
                        }
                      } else {
                        return -1;
                      }
                    } else {
                      return -1;
                    }
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
        }
      }
    }
  }
}
