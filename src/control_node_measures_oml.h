/*
 * This file was automatically generated by oml2-scaffold V2.11.0-dirty
 * for control_node_measures version 1.0.0.
 * Please do not edit.
 */

#ifndef CONTROL_NODE_MEASURES_OML_H
#define CONTROL_NODE_MEASURES_OML_H

#ifdef __cplusplus
extern "C" {
#endif

/* Define HUGE, etc.. */
#include <math.h>
/* Get size_t and NULL from <stddef.h> */
#include <stddef.h>

#include <oml2/omlc.h>

typedef struct {
  OmlMP *consumption;
  OmlMP *radio;
  OmlMP *sniffer;
  OmlMP *event;

} oml_mps_t;


#ifdef OML_FROM_MAIN
/*
 * Only declare storage once, usually from the main
 * source, where OML_FROM_MAIN is defined
 */

static OmlMPDef oml_consumption_def[] = {
  {"timestamp_s", OML_UINT32_VALUE},
  {"timestamp_us", OML_UINT32_VALUE},
  {"power", OML_DOUBLE_VALUE},
  {"voltage", OML_DOUBLE_VALUE},
  {"current", OML_DOUBLE_VALUE},
  {NULL, (OmlValueT)0}
};

static OmlMPDef oml_radio_def[] = {
  {"timestamp_s", OML_UINT32_VALUE},
  {"timestamp_us", OML_UINT32_VALUE},
  {"channel", OML_UINT32_VALUE},
  {"rssi", OML_INT32_VALUE},
  {NULL, (OmlValueT)0}
};

static OmlMPDef oml_sniffer_def[] = {
  {"timestamp_s", OML_UINT32_VALUE},
  {"timestamp_us", OML_UINT32_VALUE},
  {"channel", OML_UINT32_VALUE},
  {"rssi", OML_INT32_VALUE},
  {"lqi", OML_UINT32_VALUE},
  {"crc_ok", OML_BOOL_VALUE},
  {"length", OML_UINT32_VALUE},
  {NULL, (OmlValueT)0}
};

static OmlMPDef oml_event_def[] = {
  {"timestamp_s", OML_UINT32_VALUE},
  {"timestamp_us", OML_UINT32_VALUE},
  {"value", OML_UINT32_VALUE},
  {"name", OML_STRING_VALUE},
  {NULL, (OmlValueT)0}
};

static oml_mps_t g_oml_mps_storage;
oml_mps_t* g_oml_mps_control_node_measures = &g_oml_mps_storage;

static inline void
oml_register_mps(void)
{
  g_oml_mps_control_node_measures->consumption = omlc_add_mp("consumption", oml_consumption_def);
  g_oml_mps_control_node_measures->radio = omlc_add_mp("radio", oml_radio_def);
  g_oml_mps_control_node_measures->sniffer = omlc_add_mp("sniffer", oml_sniffer_def);
  g_oml_mps_control_node_measures->event = omlc_add_mp("event", oml_event_def);

}

#else
/*
 * Not included from the main source, only declare the global pointer
 * to the MPs and injection helpers.
 */

extern oml_mps_t* g_oml_mps_control_node_measures;

#endif /* OML_FROM_MAIN */

static inline int
oml_inject_consumption(OmlMP *mp, uint32_t timestamp_s, uint32_t timestamp_us, double power, double voltage, double current)
{
  int ret = -1;

  OmlValueU v[5];
  omlc_zero_array(v, 5);

  omlc_set_uint32(v[0], timestamp_s);
  omlc_set_uint32(v[1], timestamp_us);
  omlc_set_double(v[2], power);
  omlc_set_double(v[3], voltage);
  omlc_set_double(v[4], current);

  ret = omlc_inject(mp, v);

  return ret;
}

static inline int
oml_inject_radio(OmlMP *mp, uint32_t timestamp_s, uint32_t timestamp_us, uint32_t channel, int32_t rssi)
{
  int ret = -1;

  OmlValueU v[4];
  omlc_zero_array(v, 4);

  omlc_set_uint32(v[0], timestamp_s);
  omlc_set_uint32(v[1], timestamp_us);
  omlc_set_uint32(v[2], channel);
  omlc_set_int32(v[3], rssi);

  ret = omlc_inject(mp, v);

  return ret;
}

static inline int
oml_inject_sniffer(OmlMP *mp, uint32_t timestamp_s, uint32_t timestamp_us, uint32_t channel, int32_t rssi, uint32_t lqi, uint8_t crc_ok, uint32_t length)
{
  int ret = -1;

  OmlValueU v[7];
  omlc_zero_array(v, 7);

  omlc_set_uint32(v[0], timestamp_s);
  omlc_set_uint32(v[1], timestamp_us);
  omlc_set_uint32(v[2], channel);
  omlc_set_int32(v[3], rssi);
  omlc_set_uint32(v[4], lqi);
  omlc_set_bool(v[5], crc_ok);
  omlc_set_uint32(v[6], length);

  ret = omlc_inject(mp, v);

  return ret;
}

static inline int
oml_inject_event(OmlMP *mp, uint32_t timestamp_s, uint32_t timestamp_us, uint32_t value, const char *name)
{
  int ret = -1;

  OmlValueU v[4];
  omlc_zero_array(v, 4);

  omlc_set_uint32(v[0], timestamp_s);
  omlc_set_uint32(v[1], timestamp_us);
  omlc_set_uint32(v[2], value);
  omlc_set_string(v[3], name);

  ret = omlc_inject(mp, v);

  omlc_reset_string(v[3]);
  return ret;
}


/* Compatibility with old applications */
#ifndef g_oml_mps
# define g_oml_mps	g_oml_mps_control_node_measures
#endif

#ifdef __cplusplus
}
#endif

#endif /* CONTROL_NODE_MEASURES_OML_H */