#include "ncore.h"

using namespace std;
using namespace sc_core;

ncore::ncore(const sc_module_name &name)
    : busy(false), interface(nullptr),
      incoming_mailbox_request("incoming_mailbox_request"),
      outgoing_mailbox_request("outgoing_mailbox_request")
{

  SC_METHOD(incoming);
  sensitive << incoming_mailbox_request;
  dont_initialize();

  SC_METHOD(outgoing);
  sensitive << outgoing_mailbox_request;
  dont_initialize();
}

void ncore::connect(ncore_interconnect_rx *inx)
{
  assert(inx);

  interface = inx;
}

bool ncore::ready() { return busy; }

ncore::~ncore() {}

void ncore::end_of_elaboration() {}

void ncore::mb_isr(payload *req)
{
  assert(req);

  incoming_mailbox.push(req);

  incoming_mailbox_request.notify(1, SC_MS);
}