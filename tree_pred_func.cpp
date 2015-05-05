int tree_predict(double *attr) {
  if(attr[6] > 0.5) {
    if(attr[9] > 0.5) {
      if(attr[3] > 2.5) {
        if(attr[3] > 3.5) {
          if(attr[10] > 0.5) {
            if(attr[11] > 1.5) {
              if(attr[2] > 0.5) {
                if(attr[12] > 0.5) {
                  return 1;
                } else {
                  if(attr[1] > 54.5) {
                    return 1;
                  } else {
                    return 1;
                  }
                }
              } else {
                if(attr[11] > 2.5) {
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
        return -1;
      }
    } else {
      if(attr[10] > 0.5) {
        if(attr[11] > 2.5) {
          if(attr[10] > 1.5) {
            return -1;
          } else {
            return -1;
          }
        } else {
          if(attr[10] > 1.5) {
            return 1;
          } else {
            if(attr[2] > 0.5) {
              if(attr[1] > 61) {
                return 1;
              } else {
                return 1;
              }
            } else {
              return 1;
            }
          }
        }
      } else {
        if(attr[11] > 1.5) {
          if(attr[11] > 2.5) {
            return -1;
          } else {
            if(attr[12] > 1.5) {
              return 1;
            } else {
              return -1;
            }
          }
        } else {
          if(attr[1] > 47) {
            if(attr[3] > 3.5) {
              return -1;
            } else {
              if(attr[3] > 2.5) {
                if(attr[1] > 50.5) {
                  if(attr[1] > 53.5) {
                    if(attr[2] > 0.5) {
                      if(attr[1] > 57.5) {
                        return -1;
                      } else {
                        return -1;
                      }
                    } else {
                      if(attr[12] > 0.5) {
                        if(attr[1] > 68) {
                          return -1;
                        } else {
                          return -1;
                        }
                      } else {
                        if(attr[1] > 57) {
                          return -1;
                        } else {
                          return -1;
                        }
                      }
                    }
                  } else {
                    return -1;
                  }
                } else {
                  return -1;
                }
              } else {
                if(attr[2] > 0.5) {
                  if(attr[1] > 57) {
                    return -1;
                  } else {
                    return -1;
                  }
                } else {
                  return 1;
                }
              }
            }
          } else {
            return -1;
          }
        }
      }
    }
  } else {
    if(attr[9] > 0.5) {
      if(attr[11] > 2.5) {
        if(attr[12] > 0.5) {
          return 1;
        } else {
          if(attr[2] > 0.5) {
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
            return -1;
          }
        }
      } else {
        if(attr[12] > 0.5) {
          if(attr[3] > 1.5) {
            if(attr[3] > 2.5) {
              if(attr[1] > 45.5) {
                if(attr[1] > 46.5) {
                  if(attr[3] > 3.5) {
                    if(attr[1] > 49) {
                      if(attr[1] > 52) {
                        if(attr[1] > 53.5) {
                          if(attr[1] > 72) {
                            return 1;
                          } else {
                            if(attr[4] > 104) {
                              if(attr[4] > 109) {
                                if(attr[2] > 0.5) {
                                  if(attr[12] > 1.5) {
                                    if(attr[10] > 1.5) {
                                      if(attr[10] > 2.5) {
                                        if(attr[1] > 56) {
                                          return 1;
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
                                    if(attr[1] > 65) {
                                      return 1;
                                    } else {
                                      if(attr[1] > 62.5) {
                                        return -1;
                                      } else {
                                        if(attr[4] > 151) {
                                          return 1;
                                        } else {
                                          if(attr[4] > 145) {
                                            return 1;
                                          } else {
                                            if(attr[5] > 171.5) {
                                              if(attr[10] > 0.5) {
                                                if(attr[11] > 1.5) {
                                                  if(attr[10] > 1.5) {
                                                    if(attr[10] > 2.5) {
                                                      return 1;
                                                    } else {
                                                      if(attr[13] > 6.5) {
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
                                                if(attr[11] > 1.5) {
                                                  return 1;
                                                } else {
                                                  return 1;
                                                }
                                              }
                                            } else {
                                              return 1;
                                            }
                                          }
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
                    return 1;
                  }
                } else {
                  return 1;
                }
              } else {
                return 1;
              }
            } else {
              if(attr[2] > 0.5) {
                return 1;
              } else {
                return -1;
              }
            }
          } else {
            return -1;
          }
        } else {
          if(attr[7] > 0.5) {
            if(attr[10] > 0.5) {
              if(attr[2] > 0.5) {
                if(attr[10] > 1.5) {
                  if(attr[10] > 2.5) {
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
            } else {
              if(attr[11] > 1.5) {
                if(attr[2] > 0.5) {
                  return 1;
                } else {
                  if(attr[1] > 45.5) {
                    return -1;
                  } else {
                    return -1;
                  }
                }
              } else {
                if(attr[2] > 0.5) {
                  if(attr[1] > 43) {
                    if(attr[1] > 55.5) {
                      return 1;
                    } else {
                      if(attr[1] > 52) {
                        return -1;
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
            }
          } else {
            if(attr[11] > 1.5) {
              if(attr[8] > 125.5) {
                if(attr[2] > 0.5) {
                  if(attr[13] > 6.5) {
                    if(attr[1] > 36.5) {
                      return 1;
                    } else {
                      return 1;
                    }
                  } else {
                    if(attr[3] > 3.5) {
                      return -1;
                    } else {
                      return -1;
                    }
                  }
                } else {
                  if(attr[8] > 142.5) {
                    if(attr[10] > 0.5) {
                      return 1;
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
              if(attr[10] > 0.5) {
                return -1;
              } else {
                if(attr[3] > 2.5) {
                  if(attr[3] > 3.5) {
                    if(attr[2] > 0.5) {
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
            }
          }
        }
      }
    } else {
      if(attr[12] > 0.5) {
        if(attr[10] > 0.5) {
          if(attr[1] > 46) {
            if(attr[3] > 1.5) {
              if(attr[3] > 2.5) {
                if(attr[1] > 50.5) {
                  if(attr[1] > 55) {
                    if(attr[11] > 1.5) {
                      if(attr[2] > 0.5) {
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
                        if(attr[12] > 2.5) {
                          if(attr[1] > 64) {
                            return 1;
                          } else {
                            return 1;
                          }
                        } else {
                          if(attr[1] > 62) {
                            return -1;
                          } else {
                            return 1;
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
              } else {
                return 1;
              }
            } else {
              if(attr[2] > 0.5) {
                return 1;
              } else {
                return -1;
              }
            }
          } else {
            return -1;
          }
        } else {
          if(attr[12] > 1.5) {
            if(attr[12] > 2.5) {
              return 1;
            } else {
              if(attr[2] > 0.5) {
                return -1;
              } else {
                if(attr[1] > 65) {
                  return -1;
                } else {
                  return -1;
                }
              }
            }
          } else {
            if(attr[11] > 1.5) {
              if(attr[11] > 2.5) {
                return -1;
              } else {
                if(attr[2] > 0.5) {
                  if(attr[1] > 53.5) {
                    return 1;
                  } else {
                    return 1;
                  }
                } else {
                  return -1;
                }
              }
            } else {
              if(attr[2] > 0.5) {
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
              } else {
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
              }
            }
          }
        }
      } else {
        if(attr[10] > 0.5) {
          if(attr[10] > 1.5) {
            if(attr[10] > 2.5) {
              if(attr[10] > 3.5) {
                return -1;
              } else {
                return 1;
              }
            } else {
              if(attr[11] > 2.5) {
                return -1;
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
            }
          } else {
            if(attr[8] > 93) {
              if(attr[3] > 1.5) {
                if(attr[8] > 115.5) {
                  if(attr[1] > 46.5) {
                    if(attr[2] > 0.5) {
                      if(attr[3] > 3.5) {
                        return -1;
                      } else {
                        return -1;
                      }
                    } else {
                      if(attr[11] > 1.5) {
                        if(attr[3] > 2.5) {
                          if(attr[3] > 3.5) {
                            if(attr[1] > 60) {
                              if(attr[1] > 66.5) {
                                return -1;
                              } else {
                                return -1;
                              }
                            } else {
                              return -1;
                            }
                          } else {
                            if(attr[7] > 0.5) {
                              if(attr[7] > 1.5) {
                                return -1;
                              } else {
                                return -1;
                              }
                            } else {
                              if(attr[1] > 52) {
                                return -1;
                              } else {
                                return -1;
                              }
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
                    return -1;
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
          if(attr[11] > 1.5) {
            if(attr[2] > 0.5) {
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
              if(attr[1] > 50.5) {
                return -1;
              } else {
                if(attr[3] > 2.5) {
                  if(attr[3] > 3.5) {
                    return -1;
                  } else {
                    if(attr[1] > 43) {
                      return -1;
                    } else {
                      return -1;
                    }
                  }
                } else {
                  if(attr[1] > 47) {
                    return -1;
                  } else {
                    if(attr[4] > 121) {
                      return -1;
                    } else {
                      return -1;
                    }
                  }
                }
              }
            }
          } else {
            if(attr[5] > 174.5) {
              if(attr[8] > 129) {
                if(attr[1] > 67.5) {
                  return -1;
                } else {
                  if(attr[4] > 99.5) {
                    if(attr[4] > 106.5) {
                      if(attr[4] > 159) {
                        return -1;
                      } else {
                        if(attr[4] > 155) {
                          return 1;
                        } else {
                          if(attr[4] > 151) {
                            return 1;
                          } else {
                            if(attr[5] > 321.5) {
                              return 1;
                            } else {
                              if(attr[4] > 145) {
                                return -1;
                              } else {
                                if(attr[3] > 1.5) {
                                  if(attr[1] > 35.5) {
                                    if(attr[1] > 39) {
                                      if(attr[5] > 178.5) {
                                        if(attr[1] > 63) {
                                          return -1;
                                        } else {
                                          if(attr[1] > 60.5) {
                                            return -1;
                                          } else {
                                            if(attr[1] > 58) {
                                              return -1;
                                            } else {
                                              if(attr[1] > 56.5) {
                                                return 1;
                                              } else {
                                                if(attr[5] > 188) {
                                                  if(attr[5] > 200) {
                                                    if(attr[5] > 207.5) {
                                                      if(attr[5] > 216.5) {
                                                        if(attr[5] > 224) {
                                                          if(attr[8] > 141.5) {
                                                            if(attr[8] > 146.5) {
                                                              if(attr[8] > 152.5) {
                                                                if(attr[8] > 154) {
                                                                  if(attr[8] > 155.5) {
                                                                    if(attr[8] > 156.5) {
                                                                      if(attr[1] > 55) {
                                                                        return -1;
                                                                      } else {
                                                                        if(attr[1] > 52.5) {
                                                                          return -1;
                                                                        } else {
                                                                          if(attr[4] > 111) {
                                                                            if(attr[1] > 50) {
                                                                              return -1;
                                                                            } else {
                                                                              if(attr[8] > 162.5) {
                                                                                if(attr[1] > 41.5) {
                                                                                  if(attr[2] > 0.5) {
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
                                                                                      return -1;
                                                                                    }
                                                                                  } else {
                                                                                    return -1;
                                                                                  }
                                                                                } else {
                                                                                  if(attr[2] > 0.5) {
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
                                                                if(attr[2] > 0.5) {
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
              return 1;
            }
          }
        }
      }
    }
  }
}
