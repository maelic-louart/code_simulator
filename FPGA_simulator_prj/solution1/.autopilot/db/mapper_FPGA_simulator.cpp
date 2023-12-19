#include "hls_signal_handler.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "ap_fixed.h"
#include "ap_int.h"
#include "hls_stream.h"
using namespace std;

namespace hls::sim
{
  template<size_t n>
  struct Byte {
    unsigned char a[n];

    Byte()
    {
      for (size_t i = 0; i < n; ++i) {
        a[i] = 0;
      }
    }

    template<typename T>
    Byte<n>& operator= (const T &val)
    {
      std::memcpy(a, &val, n);
      return *this;
    }
  };

  struct SimException : public std::exception {
    const std::string msg;
    const size_t line;
    SimException(const std::string &msg, const size_t line)
      : msg(msg), line(line)
    {
    }
  };

  void errExit(const size_t line, const std::string &msg)
  {
    std::string s;
    s += "ERROR";
//  s += '(';
//  s += __FILE__;
//  s += ":";
//  s += std::to_string(line);
//  s += ')';
    s += ": ";
    s += msg;
    s += "\n";
    fputs(s.c_str(), stderr);
    exit(1);
  }
}


namespace hls::sim
{
  struct Buffer {
    char *first;
    Buffer(char *addr) : first(addr)
    {
    }
  };

  struct DBuffer : public Buffer {
    static const size_t total = 1<<10;
    size_t ufree;

    DBuffer(size_t usize) : Buffer(nullptr), ufree(total)
    {
      first = new char[usize*ufree];
    }

    ~DBuffer()
    {
      delete[] first;
    }
  };

  struct CStream {
    char *front;
    char *back;
    size_t num;
    size_t usize;
    std::list<Buffer*> bufs;
    bool dynamic;

    CStream() : front(nullptr), back(nullptr),
                num(0), usize(0), dynamic(true)
    {
    }

    ~CStream()
    {
      for (Buffer *p : bufs) {
        delete p;
      }
    }

    template<typename T>
    T* data()
    {
      return (T*)front;
    }

    template<typename T>
    void transfer(hls::stream<T> *param)
    {
      while (!empty()) {
        param->write(*(T*)nextRead());
      }
    }

    bool empty();
    char* nextRead();
    char* nextWrite();
  };

  bool CStream::empty()
  {
    return num == 0;
  }

  char* CStream::nextRead()
  {
    assert(num > 0);
    char *res = front;
    front += usize;
    if (dynamic) {
      if (++static_cast<DBuffer*>(bufs.front())->ufree == DBuffer::total) {
        if (bufs.size() > 1) {
          bufs.pop_front();
          front = bufs.front()->first;
        } else {
          front = back = bufs.front()->first;
        }
      }
    }
    --num;
    return res;
  }

  char* CStream::nextWrite()
  {
    if (dynamic) {
      if (static_cast<DBuffer*>(bufs.back())->ufree == 0) {
        bufs.push_back(new DBuffer(usize));
        back = bufs.back()->first;
      }
      --static_cast<DBuffer*>(bufs.back())->ufree;
    }
    char *res = back;
    back += usize;
    ++num;
    return res;
  }

  std::list<CStream> streams;
  std::map<char*, CStream*> prebuilt;

  CStream* createStream(size_t usize)
  {
    streams.emplace_front();
    CStream &s = streams.front();
    {
      s.dynamic = true;
      s.bufs.push_back(new DBuffer(usize));
      s.front = s.bufs.back()->first;
      s.back = s.front;
      s.num = 0;
      s.usize = usize;
    }
    return &s;
  }

  template<typename T>
  CStream* createStream(hls::stream<T> *param)
  {
    CStream *s = createStream(sizeof(T));
    {
      s->dynamic = true;
      while (!param->empty()) {
        T data = param->read();
        memcpy(s->nextWrite(), (char*)&data, sizeof(T));
      }
      prebuilt[s->front] = s;
    }
    return s;
  }

  template<typename T>
  CStream* createStream(T *param, size_t usize)
  {
    streams.emplace_front();
    CStream &s = streams.front();
    {
      s.dynamic = false;
      s.bufs.push_back(new Buffer((char*)param));
      s.front = s.back = s.bufs.back()->first;
      s.usize = usize;
      s.num = ~0UL;
    }
    prebuilt[s.front] = &s;
    return &s;
  }

  CStream* findStream(char *buf)
  {
    return prebuilt.at(buf);
  }
}
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
unsigned int ap_apatb_snr_strm_cap_bc;
static AESL_RUNTIME_BC __xlx_snr_strm_V_size_Reader("../tv/stream_size/stream_size_in_snr_strm.dat");
unsigned int ap_apatb_f_shift_strm_cap_bc;
static AESL_RUNTIME_BC __xlx_f_shift_strm_V_size_Reader("../tv/stream_size/stream_size_in_f_shift_strm.dat");
unsigned int ap_apatb_dynamic_information_init_strm_cap_bc;
static AESL_RUNTIME_BC __xlx_dynamic_information_init_strm_V_size_Reader("../tv/stream_size/stream_size_in_dynamic_information_init_strm.dat");
unsigned int ap_apatb_falsification_information_strm_cap_bc;
static AESL_RUNTIME_BC __xlx_falsification_information_strm_V_size_Reader("../tv/stream_size/stream_size_in_falsification_information_strm.dat");
unsigned int ap_apatb_static_information_strm_cap_bc;
static AESL_RUNTIME_BC __xlx_static_information_strm_V_size_Reader("../tv/stream_size/stream_size_in_static_information_strm.dat");
unsigned int ap_apatb_start_e_cap_bc;
static AESL_RUNTIME_BC __xlx_start_e_V_size_Reader("../tv/stream_size/stream_size_in_start_e.dat");
unsigned int ap_apatb_data_obs_strm_cap_bc;
static AESL_RUNTIME_BC __xlx_data_obs_strm_V_size_Reader("../tv/stream_size/stream_size_out_data_obs_strm.dat");
unsigned int ap_apatb_I_obs_strm_e_cap_bc;
static AESL_RUNTIME_BC __xlx_I_obs_strm_e_V_size_Reader("../tv/stream_size/stream_size_out_I_obs_strm_e.dat");
unsigned int ap_apatb_Q_obs_strm_e_cap_bc;
static AESL_RUNTIME_BC __xlx_Q_obs_strm_e_V_size_Reader("../tv/stream_size/stream_size_out_Q_obs_strm_e.dat");
unsigned int ap_apatb_I_obs_strm_c_cap_bc;
static AESL_RUNTIME_BC __xlx_I_obs_strm_c_V_size_Reader("../tv/stream_size/stream_size_out_I_obs_strm_c.dat");
unsigned int ap_apatb_Q_obs_strm_c_cap_bc;
static AESL_RUNTIME_BC __xlx_Q_obs_strm_c_V_size_Reader("../tv/stream_size/stream_size_out_Q_obs_strm_c.dat");
unsigned int ap_apatb_longitude_strm_out_cap_bc;
static AESL_RUNTIME_BC __xlx_longitude_strm_out_V_size_Reader("../tv/stream_size/stream_size_out_longitude_strm_out.dat");
unsigned int ap_apatb_latitude_strm_out_cap_bc;
static AESL_RUNTIME_BC __xlx_latitude_strm_out_V_size_Reader("../tv/stream_size/stream_size_out_latitude_strm_out.dat");
unsigned int ap_apatb_data_out_strm_cap_bc;
static AESL_RUNTIME_BC __xlx_data_out_strm_V_size_Reader("../tv/stream_size/stream_size_out_data_out_strm.dat");
using hls::sim::Byte;
struct __cosim_s12__ { char data[12]; };
struct __cosim_s24__ { char data[24]; };
struct __cosim_s23__ { char data[32]; };
struct __cosim_s21__ { char data[32]; };
struct __cosim_s16__ { char data[16]; };
struct __cosim_s32__ { char data[32]; };
extern "C" void FPGA_simulator(int*, int*, __cosim_s12__*, __cosim_s12__*, __cosim_s24__*, char*, __cosim_s23__*, int*, int*, int*, int*, int*, int*, __cosim_s21__*);
extern "C" void apatb_FPGA_simulator_hw(volatile void * __xlx_apatb_param_snr_strm, volatile void * __xlx_apatb_param_f_shift_strm, volatile void * __xlx_apatb_param_dynamic_information_init_strm, volatile void * __xlx_apatb_param_falsification_information_strm, volatile void * __xlx_apatb_param_static_information_strm, volatile void * __xlx_apatb_param_start_e, volatile void * __xlx_apatb_param_data_obs_strm, volatile void * __xlx_apatb_param_I_obs_strm_e, volatile void * __xlx_apatb_param_Q_obs_strm_e, volatile void * __xlx_apatb_param_I_obs_strm_c, volatile void * __xlx_apatb_param_Q_obs_strm_c, volatile void * __xlx_apatb_param_longitude_strm_out, volatile void * __xlx_apatb_param_latitude_strm_out, volatile void * __xlx_apatb_param_data_out_strm) {
using hls::sim::createStream;
auto* ssnr_strm = createStream((hls::stream<int>*)__xlx_apatb_param_snr_strm);
auto* sf_shift_strm = createStream((hls::stream<int>*)__xlx_apatb_param_f_shift_strm);
auto* sdynamic_information_init_strm = createStream((hls::stream<__cosim_s12__>*)__xlx_apatb_param_dynamic_information_init_strm);
auto* sfalsification_information_strm = createStream((hls::stream<__cosim_s12__>*)__xlx_apatb_param_falsification_information_strm);
auto* sstatic_information_strm = createStream((hls::stream<__cosim_s24__>*)__xlx_apatb_param_static_information_strm);
auto* sstart_e = createStream((hls::stream<char>*)__xlx_apatb_param_start_e);
  //Create input buffer for data_obs_strm
  ap_apatb_data_obs_strm_cap_bc = __xlx_data_obs_strm_V_size_Reader.read_size();
  __cosim_s23__* __xlx_data_obs_strm_input_buffer= new __cosim_s23__[ap_apatb_data_obs_strm_cap_bc];
auto* sdata_obs_strm = createStream((hls::stream<__cosim_s23__>*)__xlx_apatb_param_data_obs_strm);
  //Create input buffer for I_obs_strm_e
  ap_apatb_I_obs_strm_e_cap_bc = __xlx_I_obs_strm_e_V_size_Reader.read_size();
  int* __xlx_I_obs_strm_e_input_buffer= new int[ap_apatb_I_obs_strm_e_cap_bc];
auto* sI_obs_strm_e = createStream((hls::stream<int>*)__xlx_apatb_param_I_obs_strm_e);
  //Create input buffer for Q_obs_strm_e
  ap_apatb_Q_obs_strm_e_cap_bc = __xlx_Q_obs_strm_e_V_size_Reader.read_size();
  int* __xlx_Q_obs_strm_e_input_buffer= new int[ap_apatb_Q_obs_strm_e_cap_bc];
auto* sQ_obs_strm_e = createStream((hls::stream<int>*)__xlx_apatb_param_Q_obs_strm_e);
  //Create input buffer for I_obs_strm_c
  ap_apatb_I_obs_strm_c_cap_bc = __xlx_I_obs_strm_c_V_size_Reader.read_size();
  int* __xlx_I_obs_strm_c_input_buffer= new int[ap_apatb_I_obs_strm_c_cap_bc];
auto* sI_obs_strm_c = createStream((hls::stream<int>*)__xlx_apatb_param_I_obs_strm_c);
  //Create input buffer for Q_obs_strm_c
  ap_apatb_Q_obs_strm_c_cap_bc = __xlx_Q_obs_strm_c_V_size_Reader.read_size();
  int* __xlx_Q_obs_strm_c_input_buffer= new int[ap_apatb_Q_obs_strm_c_cap_bc];
auto* sQ_obs_strm_c = createStream((hls::stream<int>*)__xlx_apatb_param_Q_obs_strm_c);
  //Create input buffer for longitude_strm_out
  ap_apatb_longitude_strm_out_cap_bc = __xlx_longitude_strm_out_V_size_Reader.read_size();
  int* __xlx_longitude_strm_out_input_buffer= new int[ap_apatb_longitude_strm_out_cap_bc];
auto* slongitude_strm_out = createStream((hls::stream<int>*)__xlx_apatb_param_longitude_strm_out);
  //Create input buffer for latitude_strm_out
  ap_apatb_latitude_strm_out_cap_bc = __xlx_latitude_strm_out_V_size_Reader.read_size();
  int* __xlx_latitude_strm_out_input_buffer= new int[ap_apatb_latitude_strm_out_cap_bc];
auto* slatitude_strm_out = createStream((hls::stream<int>*)__xlx_apatb_param_latitude_strm_out);
  //Create input buffer for data_out_strm
  ap_apatb_data_out_strm_cap_bc = __xlx_data_out_strm_V_size_Reader.read_size();
  __cosim_s21__* __xlx_data_out_strm_input_buffer= new __cosim_s21__[ap_apatb_data_out_strm_cap_bc];
auto* sdata_out_strm = createStream((hls::stream<__cosim_s21__>*)__xlx_apatb_param_data_out_strm);
  // DUT call
  FPGA_simulator(ssnr_strm->data<int>(), sf_shift_strm->data<int>(), sdynamic_information_init_strm->data<__cosim_s12__>(), sfalsification_information_strm->data<__cosim_s12__>(), sstatic_information_strm->data<__cosim_s24__>(), sstart_e->data<char>(), sdata_obs_strm->data<__cosim_s23__>(), sI_obs_strm_e->data<int>(), sQ_obs_strm_e->data<int>(), sI_obs_strm_c->data<int>(), sQ_obs_strm_c->data<int>(), slongitude_strm_out->data<int>(), slatitude_strm_out->data<int>(), sdata_out_strm->data<__cosim_s21__>());
ssnr_strm->transfer((hls::stream<int>*)__xlx_apatb_param_snr_strm);
sf_shift_strm->transfer((hls::stream<int>*)__xlx_apatb_param_f_shift_strm);
sdynamic_information_init_strm->transfer((hls::stream<__cosim_s12__>*)__xlx_apatb_param_dynamic_information_init_strm);
sfalsification_information_strm->transfer((hls::stream<__cosim_s12__>*)__xlx_apatb_param_falsification_information_strm);
sstatic_information_strm->transfer((hls::stream<__cosim_s24__>*)__xlx_apatb_param_static_information_strm);
sstart_e->transfer((hls::stream<char>*)__xlx_apatb_param_start_e);
sdata_obs_strm->transfer((hls::stream<__cosim_s23__>*)__xlx_apatb_param_data_obs_strm);
sI_obs_strm_e->transfer((hls::stream<int>*)__xlx_apatb_param_I_obs_strm_e);
sQ_obs_strm_e->transfer((hls::stream<int>*)__xlx_apatb_param_Q_obs_strm_e);
sI_obs_strm_c->transfer((hls::stream<int>*)__xlx_apatb_param_I_obs_strm_c);
sQ_obs_strm_c->transfer((hls::stream<int>*)__xlx_apatb_param_Q_obs_strm_c);
slongitude_strm_out->transfer((hls::stream<int>*)__xlx_apatb_param_longitude_strm_out);
slatitude_strm_out->transfer((hls::stream<int>*)__xlx_apatb_param_latitude_strm_out);
sdata_out_strm->transfer((hls::stream<__cosim_s21__>*)__xlx_apatb_param_data_out_strm);
}
